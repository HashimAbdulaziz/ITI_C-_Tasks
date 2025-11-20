#ifndef READKEY_H
#define READKEY_H

// Key codes your program will use
enum Key {
    KEY_UP,
    KEY_DOWN,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_OTHER
};


#if !defined(_WIN32)
// Linux: enable raw mode
void enableRawMode();
// Linux: disable raw mode (restores terminal to normal mode)
void disableRawMode();
#endif

// returns Key enum type
Key readKey();

#endif
