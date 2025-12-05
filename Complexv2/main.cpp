#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 1.0);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2: " << (c1 + c2) << endl;

    cout << "-c1: " << -c1 << endl;

    cout << "c2: " << c2 << endl;
    cout << "++c2: " << ++c2 << endl; // Should be 2+1i
    cout << "c2++: " << c2++ << endl; // Should display 2+1i, then become 3+1i
    cout << "c2: " << c2 << endl;    // Should be 3+1i

    return 0;
}
