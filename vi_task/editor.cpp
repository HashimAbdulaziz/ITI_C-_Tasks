#include "editor.h"
#include "meshostdio.h"
#include <cstring> // for strlen

// Array of pointers (The Instructor will love this)
char* lines[MAX_ROWS];

int cursorX = 0;
int cursorY = 0;

void initEditor() {
    // 1. If lines exist, clear them (Persistence logic handled in main now, but safety here)
    if (lines[0] != nullptr) return; // Already initialized

    // 2. Allocate memory for EACH line
    for (int i = 0; i < MAX_ROWS; i++) {
        lines[i] = new char[ROW_CAPACITY];
        lines[i][0] = '\0'; // Start empty
    }

    cursorX = 0;
    cursorY = 0;
}

void destroyEditor() {
    for (int i = 0; i < MAX_ROWS; i++) {
        if (lines[i] != nullptr) {
            delete[] lines[i];
            lines[i] = nullptr;
        }
    }
}

// Helper to get length of CURRENT line
int getCurrentRowLength() {
    int len = 0;
    while (lines[cursorY][len] != '\0') len++;
    return len;
}

void insertChar(char c) {
    int len = getCurrentRowLength();

    // Check safety: don't overflow line width
    if (len < ROW_CAPACITY - 1) {
        // Shift chars to the right (to insert in middle)
        for (int i = len; i >= cursorX; i--) {
            // Pointer arithmetic: *(lines[cursorY] + i + 1) ...
            lines[cursorY][i + 1] = lines[cursorY][i];
        }

        // Insert
        lines[cursorY][cursorX] = c;
        cursorX++;
    }
}

void deleteChar() {
    if (cursorX > 0) {
        cursorX--;
        int len = getCurrentRowLength();

        // Shift chars to the left
        for (int i = cursorX; i < len; i++) {
            lines[cursorY][i] = lines[cursorY][i+1];
        }
    }
}

void addNewLine() {
    // "Enter" simply moves to the start of the next line
    if (cursorY < MAX_ROWS - 1) {
        cursorY++;
        cursorX = 0;
    }
}

void moveCursorLeft() {
    if (cursorX > 0) cursorX--;
}

void moveCursorRight() {
    int len = getCurrentRowLength();
    if (cursorX < len) cursorX++;
}

void moveCursorUp() {
    if (cursorY > 0) {
        cursorY--;
        // Snap cursorX if the previous line is shorter
        int len = getCurrentRowLength();
        if (cursorX > len) cursorX = len;
    }
}

void moveCursorDown() {
    if (cursorY < MAX_ROWS - 1) {
        cursorY++;
        // Snap cursorX if the next line is shorter
        int len = getCurrentRowLength();
        if (cursorX > len) cursorX = len;
    }
}

void renderEditorScreen() {
    // Loop through all lines and print them
    for (int i = 0; i < MAX_ROWS; i++) {
        PrintWord(0, i, lines[i], COLOR_WHITE);

        // Visual cleanup: Print extra spaces to erase deleted chars
        // (Simple way to handle deleting without clearing screen)
        PrintWord(strlen(lines[i]), i, "  ", COLOR_BLACK);
    }
    moveCursor(cursorX, cursorY);
    cout.flush();
}
