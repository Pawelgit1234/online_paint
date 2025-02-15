#include <cstdint>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/program_options.hpp>

#include "network/server.hpp"
#include "utils/log.hpp"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    initLogging();

    try
    {

        po::options_description desc("Online paint server options");
        desc.add_options()
            ("help,h", "Shows information about options")
            ("port,p", po::value<uint16_t>(), "Servers port");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.count("port"))
        {
            boost::asio::io_context io_context;
            Server server(io_context, vm["port"].as<uint16_t>());
            io_context.run();
        }
    }
    catch(const std::exception& e)
    {
        BOOST_LOG_TRIVIAL(fatal) << e.what();
    }

    return 0;
}