#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "Stack.h"

using namespace std;

// Constructor
template <typename T>
Stack<T>::Stack(int size) {
    capacity = size;
    arr = new T[capacity];
    topIndex = -1;
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

// Push
template <typename T>
void Stack<T>::push(T element) {
    if (isFull()) {
        cout << "Error: Stack is full!" << endl;
        return;
    }
    topIndex++;
    arr[topIndex] = element;
}

// Pop
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Error: Stack is empty!" << endl;
        return T(); // Return default value
    }
    T poppedValue = arr[topIndex];
    topIndex--;
    return poppedValue;
}

// Peek
template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        cout << "Error: Stack is empty!" << endl;
        return T();
    }
    return arr[topIndex];
}

// Is Empty
template <typename T>
bool Stack<T>::isEmpty() const {
    return topIndex == -1;
}

// Is Full
template <typename T>
bool Stack<T>::isFull() const {
    return topIndex == capacity - 1;
}

#endif
