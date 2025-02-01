#include "io.hpp"

Action getAction()
{
#ifdef _WIN32
    if (GetAsyncKeyState(VK_UP) & 0x8000) return Action::MOVE_UP;
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) return Action::MOVE_DOWN;
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) return Action::MOVE_LEFT;
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) return Action::MOVE_RIGHT;
    if (GetAsyncKeyState('Q') & 0x8000) return Action::QUIT;
    if (GetAsyncKeyState('1') & 0x8000) return Action::SET_BLACK;
    if (GetAsyncKeyState('2') & 0x8000) return Action::SET_RED;
    if (GetAsyncKeyState('3') & 0x8000) return Action::SET_GREEN;
    if (GetAsyncKeyState('4') & 0x8000) return Action::SET_YELLOW;
    if (GetAsyncKeyState('5') & 0x8000) return Action::SET_BLUE;
    if (GetAsyncKeyState('6') & 0x8000) return Action::SET_MAGENTA;
    if (GetAsyncKeyState('7') & 0x8000) return Action::SET_CYAN;
    if (GetAsyncKeyState('8') & 0x8000) return Action::SET_WHITE;
    if (GetAsyncKeyState('9') & 0x8000) return Action::DELETE_DOT;
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    int ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch == 27 && getchar() == 91)
    {
        switch (getchar())
        {
            case 'A': return Action::MOVE_UP;
            case 'B': return Action::MOVE_DOWN;
            case 'C': return Action::MOVE_RIGHT;
            case 'D': return Action::MOVE_LEFT;
        }
    }

    switch (ch)
    {
        case 'q': return Action::QUIT;
        case '1': return Action::SET_BLACK;
        case '2': return Action::SET_RED;
        case '3': return Action::SET_GREEN;
        case '4': return Action::SET_YELLOW;
        case '5': return Action::SET_BLUE;
        case '6': return Action::SET_MAGENTA;
        case '7': return Action::SET_CYAN;
        case '8': return Action::SET_WHITE;
        case '9': return Action::DELETE_DOT;
    }
#endif

    return Action::NOTHING;
}
