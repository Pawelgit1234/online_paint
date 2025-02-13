#include "log.hpp"

void initLogging()
{
    boost::log::add_file_log(
        boost::log::keywords::file_name = "logs/log_%N.log", 
        boost::log::keywords::rotation_size = 10 * 1024 * 1024,  // 10 MB
        boost::log::keywords::format = "[%TimeStamp%] [%Severity%]: %Message%",
        boost::log::keywords::auto_flush = true
    );

    boost::log::add_console_log(
        std::cerr,
        boost::log::keywords::format = "[%TimeStamp%] [%Severity%]: %Message%"
    );

    boost::log::add_common_attributes();

    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::debug
    );
}