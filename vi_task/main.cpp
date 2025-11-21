#include "meshostdio.h"
#include "readkey.h"
#include "interactive.h"


using namespace std;


int main() {
    ClearScreen();

    // We only need to call the interactive menu.
    // It handles drawing and user input.
    DrawMenuWithSelection();

    return 0;
}
