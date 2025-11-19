#include "magicGen.h"


int main() {
    int n;

    ClearScreen();
    resetColor();

    cout << "Enter odd number for Magic Square (e.g., 3, 5, 7): ";
    cin >> n;

    if (n % 2 == 0 || n <= 0) {
        cout << "Please enter a positive odd number!" << endl;
        return 1;
    }

    GenerateMagicSquare(n);

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
