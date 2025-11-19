#include "meshostdio.h"
#include "readkey.h"

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
                // Color only the selected word (text) - e.g. light cyan
                setColor(COLOR_LIGHT_CYAN);
                DrawBoxCentered(items[i], startYPositions[i]);
                resetColor();
            }
            else {
                // Normal color for others
                DrawBoxCentered(items[i], startYPositions[i]);
            }
        }
        cout.flush();

        Key k = readKey();

        if (k == KEY_DOWN) {
            selectedIndex++;
            if (selectedIndex >= itemCount)
                selectedIndex = 0;
        }
        else if (k == KEY_UP) {
            selectedIndex--;
            if (selectedIndex < 0)
                selectedIndex = itemCount - 1;
        }
        else if (k == KEY_ENTER) {

            if(selectedIndex == 0){ // "New" selected
                ClearScreen();
                PrintWord(25, 10, "WE LOVE Eng,Mina & Windows !!!", COLOR_LIGHT_RED);
                cout.flush(); // Make sure text is printed

                // Stay on this screen and wait ONLY for Backspace
                while (readKey() != KEY_BACKSPACE) {
                    // Do nothing, just wait
                }
                // Backspace was pressed, so we'll loop back to the main menu
            }
            else if(selectedIndex == 1){ // "Display" selected
                ClearScreen();
                PrintWord(10, 5, "you are on Display Mode", COLOR_LIGHT_RED);
                cout.flush(); // Make sure text is printed

                // ***MODIFICATION:***
                // Stay on this screen and wait ONLY for Backspace
                while (readKey() != KEY_BACKSPACE) {
                    // Do nothing, just wait
                }
                // Backspace was pressed, so we'll loop back to the main menu
            }
            else if (selectedIndex == 2) { // "Exit" selected
                // This is the only case where we break the main loop
                break;
            }

        }
    }
}
