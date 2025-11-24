#ifndef EDITOR_H
#define EDITOR_H

// --- Array of pointers (one for each line) ---
const int MAX_ROWS = 20;      // Maximum number of lines
const int ROW_CAPACITY = 80;  // Max length of one line

// lines is an array of pointers. lines[0] is the first row, etc.
extern char* lines[MAX_ROWS];

extern int cursorX;
extern int cursorY;

void initEditor();
void destroyEditor();

void insertChar(char c);
void deleteChar();
void addNewLine(); // For Enter key

void moveCursorLeft();
void moveCursorRight();
void moveCursorUp();   // New
void moveCursorDown(); // New

void renderEditorScreen();

#endif
