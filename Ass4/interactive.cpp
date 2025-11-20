#include "meshostdio.h"
#include "readkey.h"
#include "Employee.h" // Include the new data structure
#include <limits> // Required for numeric input handling
#include <cstdio> // For fflush
#include <algorithm> // For std::any_of
#include <cctype> // For isdigit, toupper
#include <regex> // For robust date validation

// --- Validation Helper Functions ---

// Checks if a string contains any numeric digit
bool contains_number(const string& str) {
    return std::any_of(str.begin(), str.end(), ::isdigit);
}

// Checks if the gender is M, F, or O (case-insensitive)
bool isValidGender(const string& g) {
    if (g.length() != 1) return false;
    char c = toupper(g[0]);
    return (c == 'M' || c == 'F' || c == 'O');
}

// Performs a basic YYYY-M-D or YYYY-MM-DD format check using regex.
// Accepts YYYY-[1-12]-[1-31]. It does not check for leap years or valid days for each month.
bool isValidDate(const string& d) {
    // Regex for YYYY-M{1,2}-D{1,2}
    // ^: start of string
    // \d{4}: exactly four digits for the year
    // -: literal hyphen
    // (0?[1-9]|1[0-2]): month (1-9 or 01-09, or 10-12)
    // -: literal hyphen
    // (0?[1-9]|[12]\d|3[01]): day (1-9 or 01-09, or 10-29, or 30-31)
    // $: end of string
    const std::regex date_regex("^\\d{4}-(0?[1-9]|1[0-2])-(0?[1-9]|[12]\\d|3[01])$");

    return std::regex_match(d, date_regex);
}

// Function to handle employee data input
void InputEmployeeData() {
    ClearScreen();

    // Setup input area coordinates
    int startX = 5;
    int currentY = 3;
    int errorX = startX + 40; // X position for error messages
    int inputFieldWidth = 20; // Width to clear previous input

    PrintWord(startX, 1, "--- Enter New Employee Data ---", COLOR_YELLOW);

    // Create a new employee object
    Employee newEmployee;
    newEmployee.id = nextEmployeeId++; // Assign ID and increment counter

    // Print ID
    PrintWord(startX, currentY, "Employee ID: " + to_string(newEmployee.id), COLOR_BRIGHT_WHITE);
    currentY += 2;

    // --- First Name ---
    int firstNameY = currentY;
    do {
        PrintWord(startX, firstNameY, "First Name: ", COLOR_CYAN);
        moveCursor(startX + 25, firstNameY);
        PrintWord(startX + 25, firstNameY, string(inputFieldWidth, ' '), COLOR_BLACK); // Clear previous input text area
        moveCursor(startX + 25, firstNameY);

        // Temporarily disable raw mode for standard input
#if !defined(_WIN32)
        disableRawMode();
#endif
        // FIX: Removed cin.ignore() here. The ENTER from menu selection is consumed by readKey().
        // Starting with a clean buffer ensures getline waits for the first input.
        getline(cin, newEmployee.firstName);

        if (newEmployee.firstName.empty() || contains_number(newEmployee.firstName)) {
            PrintWord(errorX, firstNameY, " *Name cannot be empty or contain numbers! *", COLOR_RED);
        } else {
            PrintWord(errorX, firstNameY, string(45, ' '), COLOR_BLACK); // Clear error message
            break;
        }
    } while (true);
    currentY += 2;

    // --- Last Name ---
    int lastNameY = currentY;
    do {
        PrintWord(startX, lastNameY, "Last Name: ", COLOR_CYAN);
        moveCursor(startX + 25, lastNameY);
        PrintWord(startX + 25, lastNameY, string(inputFieldWidth, ' '), COLOR_BLACK); // Clear previous input text area
        moveCursor(startX + 25, lastNameY);

        // NOTE: No cin.ignore() needed here since previous input was getline (consumed its newline).
        getline(cin, newEmployee.lastName);

        if (newEmployee.lastName.empty() || contains_number(newEmployee.lastName)) {
            PrintWord(errorX, lastNameY, " *Name cannot be empty or contain numbers! *", COLOR_RED);
        } else {
            PrintWord(errorX, lastNameY, string(45, ' '), COLOR_BLACK); // Clear error message
            break;
        }
    } while (true);
    currentY += 2;

    // --- Age (with numeric validation) ---
    int ageY = currentY;
    do {
        PrintWord(startX, ageY, "Age (Number): ", COLOR_CYAN);
        moveCursor(startX + 25, ageY);
        PrintWord(startX + 25, ageY, "       ", COLOR_BLACK); // Clear previous input
        moveCursor(startX + 25, ageY);

        if (cin >> newEmployee.age && newEmployee.age >= 18 && newEmployee.age <= 100) {
            PrintWord(errorX, ageY, string(45, ' '), COLOR_BLACK); // Clear error message
            break;
        }

        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input

        PrintWord(errorX, ageY, " *Invalid age (18-100) or non-numeric! *", COLOR_RED);

    } while (true);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear stream buffer after numeric input
    currentY += 2;

    // --- Gender ---
    int genderY = currentY;
    do {
        PrintWord(startX, genderY, "Gender (M/F/O): ", COLOR_CYAN);
        moveCursor(startX + 25, genderY);
        PrintWord(startX + 25, genderY, "  ", COLOR_BLACK); // Clear previous input
        moveCursor(startX + 25, genderY);

        string tempGender;
        cin >> tempGender;

        if (isValidGender(tempGender)) {
            newEmployee.gender = tempGender;
            PrintWord(errorX, genderY, string(45, ' '), COLOR_BLACK); // Clear error message
            break;
        } else {
            PrintWord(errorX, genderY, " *Invalid gender. Use M, F, or O only! *", COLOR_RED);
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (true);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear line after single-word input
    currentY += 2;

    // --- Date ---
    int dateY = currentY;
    do {
        PrintWord(startX, dateY, "Date (YYYY-M-D or YYYY-MM-DD): ", COLOR_CYAN);
        moveCursor(startX + 25 + 10, dateY); // Moved input position slightly due to longer label
        PrintWord(startX + 25 + 10, dateY, string(inputFieldWidth, ' '), COLOR_BLACK); // Clear previous input
        moveCursor(startX + 25 + 10, dateY);

        string tempDate;
        cin >> tempDate;

        if (isValidDate(tempDate)) {
            newEmployee.date = tempDate;
            PrintWord(errorX, dateY, string(45, ' '), COLOR_BLACK); // Clear error message
            break;
        } else {
            PrintWord(errorX, dateY, " *Invalid date format. Use YYYY-M-D! *", COLOR_RED);
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (true);

    currentY += 3;

    // Store the employee
    employees.push_back(newEmployee);
    PrintWord(startX, currentY, "Employee added successfully! Press BACKSPACE to return to menu...", COLOR_LIGHT_GREEN);
    cout.flush(); // Ensure output is immediately visible

    // FIX: Re-enable raw mode before starting the key-reading loop (Re-entering Raw Mode)
#if !defined(_WIN32)
    enableRawMode();
#endif

    // Wait ONLY for Backspace (readKey() now requires raw mode to be active)
    while (readKey() != KEY_BACKSPACE) {
        // Do nothing, just wait
    }
}

// Function to display all employee data
void DisplayEmployees() {
    ClearScreen();

    int startX = 3;
    int currentY = 3;

    PrintWord(startX, 1, "--- Employee List ---", COLOR_YELLOW);

    if (employees.empty()) {
        PrintWord(startX, currentY, "No employees registered yet.", COLOR_LIGHT_RED);
    } else {
        // Print Header
        // The numbers are padding for a neat table display
        string header = "ID   | Name                   | Age | Gender | Date";
        PrintWord(startX, currentY, header, COLOR_LIGHT_CYAN);
        currentY++;
        PrintWord(startX, currentY, "--------------------------------------------------------", COLOR_WHITE);
        currentY++;

        // Print Employee Data
        for (const auto& emp : employees) {
            string fullName = emp.firstName + " " + emp.lastName;
            string paddedName = fullName.substr(0, 20);
            while (paddedName.length() < 20) paddedName += " "; // Pad to 20 chars

            string line =
                to_string(emp.id) + " | " +
                paddedName + " | " +
                (emp.age < 10 ? " " : "") + to_string(emp.age) + " | " + // Pad age
                emp.gender + " | " +
                emp.date;

            PrintWord(startX, currentY, line, COLOR_WHITE);
            currentY++;
        }
    }

    PrintWord(startX, currentY + 2, "Press BACKSPACE to return to menu...", COLOR_MAGENTA);
    cout.flush(); // Ensure output is immediately visible

    // Wait ONLY for Backspace
    while (readKey() != KEY_BACKSPACE) {
        // Do nothing, just wait
    }
}


// Modified menu function implementation
void DrawMenuWithSelection() {
    const int itemCount = 3;
    string items[itemCount] = {"New Employee", "Display All", "Exit"}; // Updated text

    int width, height;
    GetTerminalSize(width, height);
    int midY = height / 2;

    int startYPositions[itemCount] = { midY - 5, midY - 1, midY + 3 };

    int selectedIndex = 0;

    // FIX: Enable Raw Mode once at the start of the menu loop on Linux/non-Windows
#if !defined(_WIN32)
    enableRawMode();
#endif

    while (true) {
        ClearScreen();

        for (int i = 0; i < itemCount; i++) {
            if (i == selectedIndex) {
                // Highlight selected item in light cyan
                setColor(COLOR_LIGHT_CYAN);
                DrawBoxCentered(items[i], startYPositions[i]);
                resetColor();
            }
            else {
                // Normal color for others
                DrawBoxCentered(items[i], startYPositions[i]);
            }
        }

        // Display user hint
        PrintWord(5, height - 3, "Use UP/DOWN arrows to select, ENTER to confirm, BACKSPACE to go back.", COLOR_GRAY);

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

            if(selectedIndex == 0){ // "New Employee" selected
                InputEmployeeData();
            }
            else if(selectedIndex == 1){ // "Display All" selected
                DisplayEmployees(); // This is the function call you wanted!
            }
            else if (selectedIndex == 2) { // "Exit" selected
                ClearScreen();
                PrintWord(1, 1, "Exiting application. Goodbye!", COLOR_LIGHT_RED);
                cout.flush();
                break;
            }
        }
    }

    // FIX: Disable raw mode on exit of the main menu loop on Linux/non-Windows
#if !defined(_WIN32)
    disableRawMode();
#endif
}
