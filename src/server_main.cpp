#include <boost/asio.hpp>

#include "network/server.hpp"

int main(int argc, char* argv[])
{
    boost::asio::io_context io_context;
    Server server(io_context, 8080);
    io_context.run();

    return 0;
}