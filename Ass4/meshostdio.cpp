#include "meshostdio.h"

// Move cursor
void moveCursor(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    cout << "\033[" << y + 1 << ";" << x + 1 << "H";
#endif
}

// Set color
void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    cout << "\033[" << color << "m";
#endif
}

// Reset color
void resetColor() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    cout << "\033[0m";
#endif
}

void PrintWord(int x, int y, string word, int color){
    moveCursor(x, y);
    setColor(color);
    cout << word;
    resetColor();
}

// Clear terminal
void ClearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Get terminal width/height
void GetTerminalSize(int &width, int &height) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width  = csbi.srWindow.Right  - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top  + 1;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width  = w.ws_col;
    height = w.ws_row;
#endif
}

// Draw one rectangle
void DrawBoxCentered(string text, int yLine) {
    int width, height;
    GetTerminalSize(width, height);

    int padding = 4; // spaces around text
    int boxWidth = text.size() + padding;
    int startX = (width - boxWidth) / 2;

    // Top border
    moveCursor(startX, yLine);
    cout << "+";
    for (int i = 0; i < boxWidth - 2; i++) cout << "-";
    cout << "+";

    // Middle line with text
    moveCursor(startX, yLine + 1);
    cout << "|" << " " << text << " " << "|";

    // Bottom border
    moveCursor(startX, yLine + 2);
    cout << "+";
    for (int i = 0; i < boxWidth - 2; i++) cout << "-";
    cout << "+";
}

// Final Menu
void DrawMenu() {
    ClearScreen();

    int width, height;
    GetTerminalSize(width, height);

    int midY = height / 2;

    // Draw 3 boxes, each separated by 4 rows
    DrawBoxCentered("New",     midY - 5);
    DrawBoxCentered("Display", midY - 1);
    DrawBoxCentered("Exit",    midY + 3);

    resetColor();
    cout.flush();
}
