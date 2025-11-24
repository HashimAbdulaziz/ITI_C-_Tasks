#include "readkey.h"

#if defined(_WIN32)
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
#endif

char lastReadCharacter = '\0';

#if !defined(_WIN32)
void enableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
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
            case 75: return KEY_LEFT;  // Added
            case 77: return KEY_RIGHT; // Added
            default: return KEY_OTHER;
        }
    }

    if (ch == 13)  return KEY_ENTER;
    if (ch == 8)   return KEY_BACKSPACE;
    if (ch == 27)  return KEY_ESC;

    lastReadCharacter = (char)ch;
    return KEY_OTHER;

#else
    enableRawMode();
    unsigned char c;
    read(STDIN_FILENO, &c, 1);

    if (c == 27) {
        unsigned char next;
        int result = read(STDIN_FILENO, &next, 1);

        if (result == 0) return KEY_ESC;

        if (next == '[') {
            unsigned char dir;
            read(STDIN_FILENO, &dir, 1);
            if (dir == 'A') return KEY_UP;
            if (dir == 'B') return KEY_DOWN;
            if (dir == 'C') return KEY_RIGHT; // Added
            if (dir == 'D') return KEY_LEFT;  // Added
            return KEY_OTHER;
        }
        return KEY_ESC;
    }

    if (c == 10)  return KEY_ENTER;
    if (c == 127) return KEY_BACKSPACE;

    lastReadCharacter = (char)c;
    return KEY_OTHER;
#endif
}
