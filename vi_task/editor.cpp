#include "editor.h"
#include "meshostdio.h"


/*
1. Clear screen
2. Allocate textBuffer
3. cursorPos = 0
4. Loop:
      draw text on screen
      k = readKey()

      if normal character → insertChar
      if backspace → deleteChar
      if arrow → move cursor
      if ESC or something → exit editor
 */





char* buffer = nullptr;
int length = 0;
const int capacity = 5000;
int cursorX = 0;
int cursorY = 0;


void initEditor() {
    // If buffer already exists (safety check), delete it first
    if (buffer != nullptr) {
        delete[] buffer;
    }

    buffer = new char[capacity];
    length = 0;
    buffer[0] = '\0';

    cursorX = 0;
    cursorY = 0;

    PrintWord(0, 0, "Editor started successfully!", COLOR_GREEN);

}


void insertChar(char c) {
    // Pointer Logic Tip:
    // Currently this just appends. Later, you will use pointers
    // to shift data: *(buffer + i + 1) = *(buffer + i)
    if(length < capacity - 1) {
        buffer[length] = c;
        length++;
        buffer[length] = '\0';
        cursorX++;
    }
}


void destroyEditor() {
    if (buffer != nullptr) {
        delete[] buffer;
        buffer = nullptr;
    }
}

