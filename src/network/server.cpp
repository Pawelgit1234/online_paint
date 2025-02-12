#include "server.hpp"

Server::Server(boost::asio::io_context& io_context, uint16_t port)
    : socket_(io_context, udp::endpoint(udp::v4(), port)),
    broadcastTimer_(io_context), activityTimer_(io_context)
{
    BOOST_LOG_TRIVIAL(info) << "Server " << socket_.local_endpoint().address().to_string()
    << " runs on port " << socket_.local_endpoint().port();

    receive();
    broadcast();
    checkLastActivitys();
}

void Server::receive()
{
    socket_.async_receive_from(
        boost::asio::buffer(data_, MAX_BUFFER_LENGTH), remoteEndpoint_,
        [this](boost::system::error_code ec, size_t bytes_received)
        {
            if (!ec && bytes_received > 0)
            {
                std::vector<Cursor> cursors;
                std::vector<Dot> dots;
                
                deserialize(data_.data(), cursors, dots);
                
                cursorManager_.addCursor(cursors[0]);
                dotManager_.addDots(dots);

                lastActivitys_[cursors[0].getName()] = std::chrono::steady_clock::now();
                handleNewClient(cursors[0].getName());
            }

            receive();
        }
    );
}

void Server::broadcast()
{
    std::vector<Cursor> cursors = cursorManager_.getCursors();
    std::vector<Dot> dots = dotManager_.getDots();
    std::array<uint8_t, MAX_BUFFER_LENGTH> buffer;

    serialize(cursors, dots, buffer.data());

    for (const auto& [name, endpoint] : clients_)
    {
        socket_.async_send_to(
            boost::asio::buffer(buffer, MAX_BUFFER_LENGTH), endpoint,
            [](boost::system::error_code /*ec*/, size_t /*bytes_sent*/){}
        );
    }

    broadcastTimer_.expires_after(FRAME_DURATION);
    broadcastTimer_.async_wait(
        [this](boost::system::error_code ec)
        {
            if (!ec) 
                broadcast();
        });
}

void Server::handleNewClient(char playerName)
{
    if (clients_.find(playerName) == clients_.end())
    {
        BOOST_LOG_TRIVIAL(info) << "Client (" << playerName << ") "
        << remoteEndpoint_.address().to_string() << " connected";

        clients_[playerName] = remoteEndpoint_;
    }
}
        
void Server::checkLastActivitys()
{
    const auto now = std::chrono::steady_clock::now();
    for (const auto& [name, lastActivity] : lastActivitys_)
    {
        std::chrono::duration<double> elapsed = now - lastActivity;

        if (elapsed.count() > CLIENT_TIMEOUT)
            disconnect(name);
    }

    activityTimer_.expires_after(ACTIVITY_TIME);
    activityTimer_.async_wait(
        [this](boost::system::error_code ec)
        {
            if (!ec)
                checkLastActivitys();
        });
}

void Server::disconnect(char playerName)
{
    BOOST_LOG_TRIVIAL(info) << "Client (" << playerName << ") "
    << clients_[playerName].address().to_string() << " disconnected";

    cursorManager_.deleteCursor(playerName);

    auto clientIt = clients_.find(playerName);
    clients_.erase(clientIt);

    auto lastActivityIt = lastActivitys_.find(playerName);
    lastActivitys_.erase(lastActivityIt);
}