#ifndef MESHOSTDIO_H
#define MESHOSTDIO_H

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

#ifdef _WIN32
    #include <windows.h>

    // Windows color codes
    #define COLOR_BLACK 0
    #define COLOR_BLUE 1
    #define COLOR_GREEN 2
    #define COLOR_CYAN 3
    #define COLOR_RED 4
    #define COLOR_MAGENTA 5
    #define COLOR_YELLOW 6
    #define COLOR_WHITE 7
    #define COLOR_GRAY 8
    #define COLOR_LIGHT_BLUE 9
    #define COLOR_LIGHT_GREEN 10
    #define COLOR_LIGHT_CYAN 11
    #define COLOR_LIGHT_RED 12
    #define COLOR_LIGHT_MAGENTA 13
    #define COLOR_LIGHT_YELLOW 14
    #define COLOR_BRIGHT_WHITE 15

#else
    #include <unistd.h>
    #include <sys/ioctl.h>

    // Linux ANSI color codes
    #define COLOR_BLACK 30
    #define COLOR_RED 31
    #define COLOR_GREEN 32
    #define COLOR_YELLOW 33
    #define COLOR_BLUE 34
    #define COLOR_MAGENTA 35
    #define COLOR_CYAN 36
    #define COLOR_WHITE 37

    #define COLOR_GRAY 90
    #define COLOR_LIGHT_RED 91
    #define COLOR_LIGHT_GREEN 92
    #define COLOR_LIGHT_YELLOW 93
    #define COLOR_LIGHT_BLUE 94
    #define COLOR_LIGHT_MAGENTA 95
    #define COLOR_LIGHT_CYAN 96
    #define COLOR_BRIGHT_WHITE 97

#endif

// Function declarations
void moveCursor(int x, int y);
void setColor(int color);
void resetColor();
void PrintWord(int x, int y, string word, int color);
void ClearScreen();
void GetTerminalSize(int &width, int &height);
void DrawBoxCentered(string text, int yLine);
void DrawMenu();

#endif

