#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    Complex prod = c1 * c2;
    cout << "Product: " << prod << endl;


    return 0;
}
