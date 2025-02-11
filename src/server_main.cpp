#include <boost/asio.hpp>

#include "network/server.hpp"
#include "utils/log.hpp"

int main(int argc, char* argv[])
{
    initLogging();

    try
    {
        boost::asio::io_context io_context;
        Server server(io_context, 8080);
        io_context.run();
    }
    catch(const std::exception& e)
    {
        BOOST_LOG_TRIVIAL(fatal) << e.what();
        boost::log::core::get()->flush();
        boost::log::core::get()->remove_all_sinks();
    }

    return 0;
}