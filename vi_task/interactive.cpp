#include "meshostdio.h"
#include "readkey.h"
#include "editor.h"
#include "interactive.h"
#include <cstring>

void DrawMenuWithSelection() {
    // --- STEP 1: Initialize Editor ONCE here ---
    // (So data persists as long as the menu is running)
    // Initialize pointers to nullptr first safety
    for(int i=0; i<MAX_ROWS; i++) lines[i] = nullptr;
    initEditor();
    // -------------------------------------------

    const int itemCount = 3;
    string items[itemCount] = {"New", "Display", "Exit"};
    int width, height;
    GetTerminalSize(width, height);
    int midY = height / 2;
    int startYPositions[itemCount] = { midY - 5, midY - 1, midY + 3 };
    int selectedIndex = 0;

    while (true) {
        ClearScreen();
        for (int i = 0; i < itemCount; i++) {
            if (i == selectedIndex) {
                setColor(COLOR_LIGHT_CYAN);
                DrawBoxCentered(items[i], startYPositions[i]);
                resetColor();
            } else {
                DrawBoxCentered(items[i], startYPositions[i]);
            }
        }
        cout.flush();

        Key k = readKey();

        if (k == KEY_DOWN) { selectedIndex++; if (selectedIndex >= itemCount) selectedIndex = 0; }
        else if (k == KEY_UP) { selectedIndex--; if (selectedIndex < 0) selectedIndex = itemCount - 1; }
        else if (k == KEY_ENTER) {

            // --- NEW MODE ---
            if(selectedIndex == 0){
                ClearScreen();
                // Removed initEditor() from here!
                renderEditorScreen(); // Draw what we have so far
                cout.flush();

                while (true) {
                    Key k = readKey();
                    if (k == KEY_ESC) break;

                    if (k == KEY_OTHER) {
                        insertChar(lastReadCharacter);
                    }
                    else if (k == KEY_ENTER) {
                        addNewLine();
                    }
                    else if (k == KEY_BACKSPACE) {
                        deleteChar();
                        // Erase visual artifact at the end of line
                        int len = strlen(lines[cursorY]);
                        PrintWord(len, cursorY, " ", COLOR_BLACK);
                    }
                    else if (k == KEY_LEFT) moveCursorLeft();
                    else if (k == KEY_RIGHT) moveCursorRight();
                    else if (k == KEY_UP) moveCursorUp();
                    else if (k == KEY_DOWN) moveCursorDown();

                    renderEditorScreen();
                }
            }

            // --- DISPLAY MODE ---
            else if(selectedIndex == 1){
                ClearScreen();
                PrintWord(0, 0, "--- FILE CONTENTS ---", COLOR_LIGHT_CYAN);

                // --- PRINT ALL LINES ---
                for(int i=0; i < MAX_ROWS; i++) {
                    // Only print if line has text
                    if(strlen(lines[i]) > 0) {
                        PrintWord(0, i + 2, lines[i], COLOR_WHITE);
                    }
                }

                PrintWord(0, MAX_ROWS + 3, "Press Backspace to return", COLOR_LIGHT_RED);
                cout.flush();
                while (readKey() != KEY_BACKSPACE) {}
            }

            // --- EXIT ---
            else if (selectedIndex == 2) {
                destroyEditor(); // Clean up memory ONLY on exit
                break;
            }
        }
    }
}
