#include <iostream>
#include "CustomString.h"

using namespace std;

int main() {
    CustomString s1 = "Hello";
    CustomString s2 = "World";

    CustomString s3 = s1 + " " + s2;
    cout << "Concatenation: " << s3 << std::endl;

    // Test Assignment
    CustomString s4;
    s4 = s1;
    cout << "s4: " << s4 << std::endl;

    // Test Indexing
    s1[0] = 'Y';
    cout << "s1: " << s1 << std::endl;

    // Test Equality
    if (s1 == s4)
        cout << "Equal" << std::endl;
    else
        cout << "Not Equal" << std::endl;

    return 0;
}
