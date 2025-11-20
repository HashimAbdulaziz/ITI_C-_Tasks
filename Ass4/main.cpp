#include "meshostdio.h"  // For console utilities
#include "interactive.h" // For the menu function
#include "Employee.h"    // For accessing employee data (though not strictly needed here)
#include <iostream>

using namespace std;

// This is the main application file.
// All logic is handled by the DrawMenuWithSelection function.

int main() {
    // The console environment is initialized implicitly by the other functions.

    // Start the interactive menu loop
    DrawMenuWithSelection();

    return 0;
}
