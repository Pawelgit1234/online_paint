#include "client.hpp"

Client::Client(const std::string& host, uint16_t port)
    : socket_(io_context_), serverEndpoint_(boost::asio::ip::make_address(host), port)
{
    socket_.open(udp::v4());
}

void Client::receive(std::vector<Cursor>& cursors, std::vector<Dot>& dots)
{
    udp::endpoint senderEndpoint;
    std::array<uint8_t, MAX_BUFFER_LENGTH> buffer;

    boost::system::error_code error;
    size_t bytes_received = socket_.receive_from(
        boost::asio::buffer(buffer, MAX_BUFFER_LENGTH),
        senderEndpoint, 0, error
    );

    if (error && error != boost::asio::error::would_block)
        return;

    if (bytes_received > 0)
        deserialize(buffer.data(), cursors, dots);
}

void Client::send(const Cursor& cursor, const Dot& dot)
{
    std::array<uint8_t, MAX_BUFFER_LENGTH> buffer;
    size_t bytes_length = serialize({cursor}, {dot}, buffer.data());

    socket_.send_to(
        boost::asio::buffer(buffer, bytes_length),
        serverEndpoint_
    );
}

void Client::quit()
{
    std::array<uint8_t, MAX_BUFFER_LENGTH> buffer = {QUIT_SIGNAL};

    socket_.send_to(
        boost::asio::buffer(buffer, 1),
        serverEndpoint_
    );
}

bool Client::haveDataToRead()
{
    return socket_.available() > 0;
}