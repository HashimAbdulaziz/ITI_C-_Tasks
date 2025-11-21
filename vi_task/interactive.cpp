#include "meshostdio.h"
#include "readkey.h"
#include "editor.h"
#include "interactive.h"

void DrawMenuWithSelection() {
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
            }
            else {
                DrawBoxCentered(items[i], startYPositions[i]);
            }
        }
        cout.flush();

        Key k = readKey();

        if (k == KEY_DOWN) {
            selectedIndex++;
            if (selectedIndex >= itemCount) selectedIndex = 0;
        }
        else if (k == KEY_UP) {
            selectedIndex--;
            if (selectedIndex < 0) selectedIndex = itemCount - 1;
        }
        else if (k == KEY_ENTER) {

            // ---------- NEW MODE ---------
            if(selectedIndex == 0){
                ClearScreen();
                initEditor();
                cout.flush();

                bool firstKeyPress = true;

                while (true) {
                    Key k = readKey();

                    if (k == KEY_ESC) break; // Exit editor loop

                    if (k == KEY_OTHER) {
                        // Remove "Editor started successfully!"
                        if (firstKeyPress) {
                            ClearScreen(); // Remove "Editor started successfully!"
                            firstKeyPress = false; // Never do this again
                        }
                        char c = lastReadCharacter;
                        insertChar(c);

                        // Just print the updated buffer starting at (0,0)
                        PrintWord(0,0, buffer, COLOR_WHITE);
                        // Move cursor to the correct position for the NEXT character
                        // (We use your cursorX and cursorY variables)
                        moveCursor(cursorX, cursorY);
                        // Force the update (PrintWord now has flush, but extra safety here is fine)
                        cout.flush();
                    }
                }

                // Cleanup
                destroyEditor();
                // When we break (ESC), the main loop will restart and ClearScreen()
                // will run there, wiping the editor text cleanly.
            }

            // --- DISPLAY MODE ---
            else if(selectedIndex == 1){
                ClearScreen();
                PrintWord(10, 5, "You are in Display Mode (Press Backspace to return)", COLOR_LIGHT_RED);
                cout.flush();

                while (readKey() != KEY_BACKSPACE) {
                    // Wait for backspace
                }
            }

            // --- EXIT ---
            else if (selectedIndex == 2) {
                break;
            }
        }
    }
}
