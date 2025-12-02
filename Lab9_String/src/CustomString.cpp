#include "CustomString.h"

// Default Constructor
CustomString::CustomString() : str(nullptr), length(0) {
    str = new char[1];
    str[0] = '\0';
}

// Parameterized Constructor
CustomString::CustomString(const char* val) {
    if (val) {

        length = 0;
        while (val[length] != '\0') {
            length++;
        }

        str = new char[length + 1];

        // Copy characters
        for (size_t i = 0; i < length; i++) {
            str[i] = val[i];
        }
        str[length] = '\0';

    } else {
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }
}

// Copy Constructor
CustomString::CustomString(const CustomString& other) {
    length = other.length;
    str = new char[length + 1];

    // Copy
    for (size_t i = 0; i < length; i++) {
        str[i] = other.str[i];
    }
    str[length] = '\0';
}

// Destructor
CustomString::~CustomString() {
    delete[] str;
}

// Assignment Operator (=)
CustomString& CustomString::operator=(const CustomString& other) {
    if (this == &other) return *this;

    delete[] str;

    length = other.length;
    str = new char[length + 1];

    // Manual Copy
    for (size_t i = 0; i < length; i++) {
        str[i] = other.str[i];
    }
    str[length] = '\0';

    return *this;
}

// Concatenation Operator (+)
CustomString CustomString::operator+(const CustomString& other) {
    size_t newLength = length + other.length;
    char* buffer = new char[newLength + 1];

    // Copy first string
    for (size_t i = 0; i < length; i++) {
        buffer[i] = str[i];
    }

    // Copy second string (append)
    for (size_t i = 0; i < other.length; i++) {
        buffer[length + i] = other.str[i];
    }

    buffer[newLength] = '\0'; // Terminate

    CustomString newStr(buffer);
    delete[] buffer;
    return newStr;
}

// Equality Operator (==)
bool CustomString::operator==(const CustomString& other) {
    if (length != other.length) return false;

    // Compare
    for (size_t i = 0; i < length; i++) {
        if (str[i] != other.str[i]) {
            return false;
        }
    }
    return true;
}

// Index Operator []
char& CustomString::operator[](size_t index) {
    return str[index];
}

// Output Stream <<
std::ostream& operator<<(std::ostream& os, const CustomString& obj) {
    os << obj.str;
    return os;
}

// Input Stream >>
std::istream& operator>>(std::istream& is, CustomString& obj) {
    char buffer[1000];
    is >> buffer;
    obj = CustomString(buffer);
    return is;
}

size_t CustomString::getLength() const {
    return length;
}
