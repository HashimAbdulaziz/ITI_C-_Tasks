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
    PrintWord(width / 2 - 10, startY - 2, "Magic Square (" + to_string(n) + "x" + to_string(n) + ")", COLOR_LIGHT_YELLOW);

    // Draw empty grid
    DrawGrid(n, startX, startY);
    cout.flush();
    delay(500);

    // Create a tracking array to check if cells are occupied
    vector<vector<bool>> occupied(n, vector<bool>(n, false));

    // Generate magic square using Siamese method
    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n) {
        // Mark current cell as occupied and print number
        occupied[i][j] = true;
        PrintNumberInCell(num, i, j, n, startX, startY);
        cout.flush();
        delay(200);

        num++;

        // Calculate next position (up and right)
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;

        // Check if next position is occupied
        if (occupied[ni][nj]) {
            // Move down from current position instead
            i = (i + 1) % n;
            // j stays the same
        } else {
            // Move to the new position
            i = ni;
            j = nj;
        }
    }

    // Calculate and display magic sum
    int magicSum = n * (n * n + 1) / 2;
    PrintWord(width / 2 - 10, startY + gridHeight + 2, "Magic Sum: " + to_string(magicSum), COLOR_LIGHT_GREEN);

    moveCursor(0, height - 1);
    resetColor();
}
