#include <iostream>
#include <vector>

#include "network/client.hpp"
#include "paint/objects/cursor.hpp"
#include "paint/objects/dot.hpp"
#include "paint/objects/dot_manager.hpp"
#include "paint/color.hpp"
#include "paint/render.hpp"
#include "settings.hpp"
#include "utils/io.hpp"
#include "utils/fps_counter.hpp"

int main(int argc, char* argv[])
{
    std::string host;
    std::string port;
    char name;

    std::cout << "Host: ";
    std::cin >> host;
    std::cout << "Port: ";
    std::cin >> port;
    std::cout << "Name (one letter): ";
    std::cin >> name;

    Cursor cursor(CURSOR_SPAWN_X, CURSOR_SPAWN_Y, name);
    FpsCounter fpsCounter;
    Client client(host, std::stoi(port));

    std::vector<Cursor> receivedCursors;
    std::vector<Dot> receivedDots;

    client.send(cursor, Dot(CANVAS_WIDTH, CANVAS_HEIGHT, Color::REMOVE)); // just one time for joining server

    try
    {
        while (true)
        {
            Dot dot(CANVAS_WIDTH, CANVAS_HEIGHT, Color::REMOVE); // these coordinates, because normally they are normally impossible 
            fpsCounter.update();

            Action action = getAction();
            switch (action) 
            {
            case Action::MOVE_UP:
                cursor.moveUp();
                break;
            case Action::MOVE_DOWN:
                cursor.moveDown();
                break;
            case Action::MOVE_LEFT:
                cursor.moveLeft();
                break;
            case Action::MOVE_RIGHT:
                cursor.moveRight();
                break;
            case Action::SET_BLACK:
                dot = cursor.createDot(Color::BLACK);
                break;
            case Action::SET_RED:
                dot = cursor.createDot(Color::RED);
                break;
            case Action::SET_GREEN:
                dot = cursor.createDot(Color::GREEN);
                break;
            case Action::SET_YELLOW:
                dot = cursor.createDot(Color::YELLOW);
                break;
            case Action::SET_BLUE:
                dot = cursor.createDot(Color::BLUE);
                break;
            case Action::SET_MAGENTA:
                dot = cursor.createDot(Color::MAGENTA);
                break;
            case Action::SET_CYAN:
                dot = cursor.createDot(Color::CYAN);
                break;
            case Action::SET_WHITE:
                dot = cursor.createDot(Color::WHITE);
                break;
            case Action::DELETE_DOT:
                dot = cursor.createDot(Color::REMOVE);
                break;
            case Action::QUIT:
                client.quit();
                break;
            }

            if (action == Action::QUIT)
                break;
            else if (action != Action::NOTHING)
                client.send(cursor, dot);

            if (client.haveDataToRead())
                client.receive(receivedCursors, receivedDots);

            std::cout << "\033[2J\033[H" << render(receivedCursors, receivedDots, fpsCounter);
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}