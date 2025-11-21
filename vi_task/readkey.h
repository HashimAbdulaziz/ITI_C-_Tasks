#ifndef READKEY_H
#define READKEY_H

// Key codes your program will use
enum Key {
    KEY_UP,
    KEY_DOWN,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_ESC,
    KEY_OTHER
};

extern char lastReadCharacter;

#if !defined(_WIN32)
// Linux: enable raw mode
void enableRawMode();
#endif

// returns Key enum type
Key readKey();

#endif
