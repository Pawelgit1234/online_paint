#pragma once

#ifdef _WIN32
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <cstdio>
#endif

enum class Action
{
    MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT,
    QUIT, DELETE_DOT,
    SET_BLACK, SET_RED, SET_GREEN, SET_YELLOW, SET_BLUE, SET_MAGENTA, SET_CYAN, SET_WHITE,
    NOTHING,
};

Action getAction();