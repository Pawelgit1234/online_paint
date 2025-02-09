#pragma once

#include <cstdint>
#include <unordered_map>
#include <chrono>
#include <array>

#include <boost/asio.hpp>

#include "../settings.hpp"
#include "../paint/objects/dot_manager.hpp"
#include "../paint/objects/cursor_manager.hpp"

using boost::asio::ip::udp;
using namespace std::chrono;

class Server
{
    public:
        Server(boost::asio::io_context& io_context, uint16_t port);

    private:
        void receive();
        void broadcast();
        void ping();
        void disconnect();

        udp::socket socket_;
        udp::endpoint remoteEndpoint_;
        std::array<char, MAX_BUFFER_LENGTH> data_;

        std::unordered_map<char, udp::endpoint> clients_; // name: endpoint

        DotManager dotManager_;
        CursorManager cursorManager_;
};