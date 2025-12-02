#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

    void resize();

public:
    Stack(int size = 100);
    ~Stack();

    void push(T element);
    T pop();
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;

    // Print Function
    friend ostream& operator<<(ostream& os, const Stack<T>& s) {
        if (s.isEmpty()) {
            os << "[ Empty Stack ]";
            return os;
        }
        os << "[ ";
        for (int i = s.topIndex; i >= 0; i--) {
            os << s.arr[i];
            if (i > 0) os << " | ";
        }
        os << " ] (Capacity: " << s.capacity << ")";
        return os;
    }
};


#endif
