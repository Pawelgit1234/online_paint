#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <boost/asio.hpp>

#include "serialization.hpp"
#include "../settings.hpp"
#include "../paint/objects/cursor.hpp"
#include "../paint/objects/dot.hpp"

using boost::asio::ip::udp;

class Client
{
    public:
        Client(const std::string& host, uint16_t port);

        void receive(std::vector<Cursor>& cursors, std::vector<Dot>& dots);
        void send(const Cursor& cursor, const Dot& dot);
        void quit();

        bool haveDataToRead();

    private:
        boost::asio::io_context io_context_;
        udp::socket socket_;
        udp::endpoint serverEndpoint_;
};