#pragma once

#include <cstdint>
#include <unordered_map>
#include <chrono>
#include <array>
#include <vector>

#include <boost/asio.hpp>

#include "../settings.hpp"
#include "serialization.hpp"
#include "../paint/objects/dot_manager.hpp"
#include "../paint/objects/cursor_manager.hpp"
#include "../paint/objects/cursor.hpp"
#include "../paint/objects/dot.hpp"
#include "../utils/log.hpp"

using boost::asio::ip::udp;
using namespace std::chrono;

class Server
{
    public:
        Server(boost::asio::io_context& io_context, uint16_t port);

    private:
        void receive();
        void broadcast();
        void handleNewClient(char playerName);
        void checkLastActivitys();
        void disconnect(char playerName);

        udp::socket socket_;
        udp::endpoint remoteEndpoint_;
        std::array<uint8_t, MAX_BUFFER_LENGTH> data_;

        std::unordered_map<char, udp::endpoint> clients_; // name: endpoint
        std::unordered_map<char, std::chrono::steady_clock::time_point> lastActivitys_;

        DotManager dotManager_;
        CursorManager cursorManager_;
};