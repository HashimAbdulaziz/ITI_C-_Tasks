#include <iostream>
#include "CustomString.h"

using namespace std;

int main() {
    CustomString s1 = "Hashim";
    CustomString s2 = "is the best";

    CustomString s3 = s1 + " " + s2;
    cout << "Concatenation: " << s3 << std::endl;

    CustomString s4;
    s4 = s1;
    cout << "s4: " << s4 << std::endl;

    s1[0] = 'Y';
    cout << "s1: " << s1 << std::endl;

    if (s1 == s4)
        cout << "Equal" << std::endl;
    else
        cout << "Not Equal" << std::endl;

    return 0;
}
