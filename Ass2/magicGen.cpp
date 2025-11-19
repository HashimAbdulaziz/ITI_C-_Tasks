#include "magicGen.h"


void GenerateMagicSquare(int n) {
    ClearScreen();

    int width, height;
    GetTerminalSize(width, height);

    int gridWidth = n * 7 + 1;
    int gridHeight = n * 2 + 1;
    int startX = (width - gridWidth) / 2;
    int startY = (height - gridHeight) / 2 - 2;

    // Title
    PrintWord(width / 2 - 10, startY - 2,
              "Magic Square (" + to_string(n) + "x" + to_string(n) + ")",
              COLOR_LIGHT_YELLOW);

    DrawGrid(n, startX, startY);
    cout.flush();
    delay(500);

    int i = 0;
    int j = n / 2;

    for (int num = 1; num <= n * n; num++) {

        // Print number
        PrintNumberInCell(num, i, j, n, startX, startY);
        cout.flush();
        delay(200);

        // Movement rule (no occupancy array)
        if (num % n == 0) {
            // Move down
            i = (i + 1) % n;
        } else {
            // Move up-right
            i = (i - 1 + n) % n;
            j = (j + 1) % n;
        }
    }

    // Magic sum
    int magicSum = n * (n * n + 1) / 2;
    PrintWord(width / 2 - 10, startY + gridHeight + 2,
              "Magic Sum: " + to_string(magicSum),
              COLOR_LIGHT_GREEN);

    moveCursor(0, height - 1);
    resetColor();
}

