#include <iostream>
#include <vector>

#include "paint/objects/cursor.hpp"
#include "paint/objects/dot.hpp"
#include "paint/objects/dot_manager.hpp"
#include "paint/color.hpp"
#include "paint/render.hpp"
#include "settings.hpp"
#include "utils/io.hpp"
#include "utils/fps_counter.hpp"
#include "network/client.hpp"

int main(int argc, char* argv[])
{
    char name;
    std::cin >> name;
    Cursor cursor(CURSOR_SPAWN_X, CURSOR_SPAWN_Y, name);
    FpsCounter fpsCounter;
    Client client("0.0.0.0", 8080);

    bool moved = true;
    
    while (true)
    {
        Dot dot(CANVAS_WIDTH, CANVAS_HEIGHT, Color::DELETE);
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
            dot = cursor.createDot(Color::DELETE);
            break;
        }

        if (action != Action::NOTHING)
            moved = true;
        
        if (moved)
        {
            client.send(cursor, dot);
            moved = false;
        }

        std::vector<Cursor> cursors;
        std::vector<Dot> dots;
        client.receive(cursors, dots);

        std::cout << "\033[2J\033[H" << render(dots, cursors, fpsCounter);
    }

    return 0;
}