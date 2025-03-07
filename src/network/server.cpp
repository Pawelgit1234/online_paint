#include "server.hpp"

Server::Server(boost::asio::io_context& io_context, uint16_t port)
    : socket_(io_context, udp::endpoint(udp::v4(), port)),
    broadcastTimer_(io_context), activityTimer_(io_context)
{
    udp::socket temp_socket(io_context);
    temp_socket.open(udp::v4());

    boost::asio::ip::udp::endpoint remote_endpoint(
        boost::asio::ip::make_address("8.8.8.8"), 53);

    boost::system::error_code ec;
    temp_socket.connect(remote_endpoint, ec);

    if (!ec)
    {
        BOOST_LOG_TRIVIAL(info) << "Server runs on IP: "
                                << temp_socket.local_endpoint().address().to_string()
                                << " and port: " << socket_.local_endpoint().port();
    }

    temp_socket.close();

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
            try
            {
                if (!ec && bytes_received > 0)
                {
                    if (data_[0] == QUIT_SIGNAL)
                    {
                        auto it = std::find_if(
                            clients_.begin(),
                            clients_.end(),
                            [&](const auto& client)
                            {
                                return remoteEndpoint_ == client.second;
                            });

                        quit(it->first);
                    }
                    else
                    {
                        std::vector<Cursor> cursors;
                        std::vector<Dot> dots;
                        
                        deserialize(data_.data(), cursors, dots);
                        
                        cursorManager_.addCursor(cursors[0]);
                        dotManager_.addDot(dots[0]);

                        lastActivitys_[cursors[0].getName()] = std::chrono::steady_clock::now();
                        handleNewClient(cursors[0].getName());
                    }
                }
            }
            catch(const std::exception& e)
            {
                BOOST_LOG_TRIVIAL(error) << e.what();
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

    size_t bytes_length = serialize(cursors, dots, buffer.data());

    for (const auto& [name, endpoint] : clients_)
    {
        socket_.async_send_to(
            boost::asio::buffer(buffer, bytes_length), endpoint,
            [](boost::system::error_code /*ec*/, size_t /*bytes_sent*/){}
        );
    }

    broadcastTimer_.expires_after(SERVER_DELAY_DURATION);
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
    for (auto it = lastActivitys_.begin(); it != lastActivitys_.end(); )
    {
        std::chrono::duration<double> elapsed = now - it->second;

        if (elapsed.count() > CLIENT_TIMEOUT)
        {
            disconnect(it->first);
            it = lastActivitys_.erase(it);
        } 
        else
            ++it;
    }

    activityTimer_.expires_after(ACTIVITY_TIME);
    activityTimer_.async_wait(
        [this](boost::system::error_code ec)
        {
            if (!ec)
                checkLastActivitys();
        });
}

void Server::quit(char playerName)
{
    BOOST_LOG_TRIVIAL(info) << "Client (" << playerName << ") "
    << clients_[playerName].address().to_string() << " quited";

    cursorManager_.deleteCursor(playerName);

    auto clientIt = clients_.find(playerName);
    clients_.erase(clientIt);

    auto LastActivityIt = lastActivitys_.find(playerName);
    lastActivitys_.erase(LastActivityIt);

}

void Server::disconnect(char playerName)
{
    BOOST_LOG_TRIVIAL(info) << "Client (" << playerName << ") "
    << clients_[playerName].address().to_string() << " disconnected";

    cursorManager_.deleteCursor(playerName);

    auto clientIt = clients_.find(playerName);
    clients_.erase(clientIt);
}