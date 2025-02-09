#include "server.hpp"

Server::Server(boost::asio::io_context& io_context, uint16_t port)
    : socket_(io_context, udp::endpoint(udp::v4(), port))
{
    receive();
    ping();
}

void Server::receive()
{
    socket_.async_receive_from(
        boost::asio::buffer(data_, MAX_BUFFER_LENGTH), remoteEndpoint_,
        [this](boost::system::error_code ec, size_t bytes_received)
        {
            if (!ec && bytes_received > 0)
            {

            }

            receive();
        }
    );
}

void Server::broadcast()
{

}

void Server::ping()
{

}

void Server::disconnect()
{

}