#include <iostream>
#include "Complex.h"

using namespace std;


template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:

    Stack(int size = 100);


    ~Stack();

    void push(T element);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
};

int main() {

    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    Complex prod = c1 * c2;
    cout << "Prod: " << prod << endl;


    return 0;
}
