#include <iostream>
#include <vector>

#include "paint/cursor.hpp"
#include "paint/dot.hpp"
#include "paint/dot_manager.hpp"
#include "paint/color.hpp"
#include "paint/render.hpp"
#include "settings.hpp"
#include "paint/io.hpp"

int main(int argc, char* argv[])
{
    Cursor cursor(CURSOR_SPAWN_X, CURSOR_SPAWN_Y, 'f');
    DotManager dotManager;
    
    while (true)
    {
        switch (getAction())
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
            dotManager.addDot(cursor.createDot(Color::BLACK));
            break;
        case Action::SET_RED:
            dotManager.addDot(cursor.createDot(Color::RED));
            break;
        case Action::SET_GREEN:
            dotManager.addDot(cursor.createDot(Color::GREEN));
            break;
        case Action::SET_YELLOW:
            dotManager.addDot(cursor.createDot(Color::YELLOW));
            break;
        case Action::SET_BLUE:
            dotManager.addDot(cursor.createDot(Color::BLUE));
            break;
        case Action::SET_MAGENTA:
            dotManager.addDot(cursor.createDot(Color::MAGENTA));
            break;
        case Action::SET_CYAN:
            dotManager.addDot(cursor.createDot(Color::CYAN));
            break;
        case Action::SET_WHITE:
            dotManager.addDot(cursor.createDot(Color::WHITE));
            break;
        case Action::DELETE_DOT:
            dotManager.deleteDot(cursor.getX(), cursor.getY());
            break;
        }

        std::cout << render(dotManager.getDots(), {cursor}) << "\033[H";
    }

    return 0;
}