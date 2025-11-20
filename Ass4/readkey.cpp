#include <iostream>
#include "readkey.h"

#if defined(_WIN32)
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>

    // Static storage for original terminal attributes
    static struct termios originalTerm;
    static bool originalTermSaved = false;
#endif


#if !defined(_WIN32)
// Linux: enable raw mode (sets the terminal to non-canonical, non-echoing mode)
void enableRawMode() {
    if (!originalTermSaved) {
        // Save original settings only once
        tcgetattr(STDIN_FILENO, &originalTerm);
        originalTermSaved = true;
    }
    termios term = originalTerm;
    term.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode (line buffering) and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Linux: disable raw mode (restores original settings, enabling echo/canonical mode)
void disableRawMode() {
    if (originalTermSaved) {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTerm);
    }
}
#endif

Key readKey() {
#if defined(_WIN32)
    int ch = _getch();

    if (ch == 224) {
        int ch2 = _getch();
        switch (ch2) {
            case 72: return KEY_UP;
            case 80: return KEY_DOWN;
            default: return KEY_OTHER;
        }
    }

    if (ch == 13)  return KEY_ENTER;
    if (ch == 8)   return KEY_BACKSPACE;

    return KEY_OTHER;

#else
    // IMPORTANT FIX: readKey() no longer enables raw mode.
    // The calling function (DrawMenuWithSelection or InputEmployeeData) must handle enable/disable.
    unsigned char c;

    read(STDIN_FILENO, &c, 1);

    if (c == 27) {
        // Escape sequence
        unsigned char seq[2];
        read(STDIN_FILENO, &seq[0], 1);
        read(STDIN_FILENO, &seq[1], 1);

        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': return KEY_UP;
                case 'B': return KEY_DOWN;
            }
        }
        return KEY_OTHER;
    }

    if (c == 10)  return KEY_ENTER;      // Linux Enter
    if (c == 127) return KEY_BACKSPACE;  // Linux Backspace

    return KEY_OTHER;
#endif
}
