#include <iostream>
#include "Stack.h"
#include "/home/hashim/ITI/Lab11_Stack_hard/src/Stack.cpp"

using namespace std;

int main() {

    Stack<int> s1(5);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Top: " << s1.peek() << endl;

    cout << "Popped: " << s1.pop() << endl;
    cout << "Popped: " << s1.pop() << endl;

    if (s1.isEmpty()) {
        cout << "Stack is now almost empty." << endl;
    }

    Stack<float> s2(4);
    s2.push(1.2);
    s2.push(2.0);
    s2.push(3.33);

    cout << s2 << endl;


    return 0;
}
