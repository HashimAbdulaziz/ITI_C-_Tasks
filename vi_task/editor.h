#ifndef EDITOR_H
#define EDITOR_H

extern char* buffer;
extern int length;
extern const int capacity;

extern int cursorX;
extern int cursorY;

void initEditor();
void destroyEditor(); // Added to clean up memory

void insertChar(char c);


// void deleteChar();
// void moveCursorLeft();
// void moveCursorRight();
// void renderEditorScreen();

#endif
