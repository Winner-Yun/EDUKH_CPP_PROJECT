#ifndef CONSOLECOLOR_H
#define CONSOLECOLOR_H

#include <windows.h>

// Enum for easy color selection
enum ConsoleColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    GRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    LIGHTYELLOW = 14,
    BRIGHTWHITE = 15
};

// Function to set console text + background color
inline void setConsoleColor(int fgColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | fgColor);
}

// Function to reset console to default (white text on black background)
inline void resetConsoleColor() {
    setConsoleColor(WHITE, BLACK);
}

#endif // CONSOLECOLOR_H
