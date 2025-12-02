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


template <typename T>
void Stack<T>::resize() {
    int newCapacity = capacity * 2;

    // Print to console so you see it happening
    cout << ">> Stack is full. Resizing from " << capacity
         << " to " << newCapacity << "..." << endl;

    // Create new larger array
    T* newArr = new T[newCapacity];

    // Copy old elements
    for (int i = 0; i <= topIndex; i++) {
        newArr[i] = arr[i];
    }

    // Delete old array
    delete[] arr;

    // Update pointers and variables
    arr = newArr;
    capacity = newCapacity;
}

// Push
template <typename T>
void Stack<T>::push(T element) {
    if (isFull()) {
        resize();
    }
    topIndex++;
    arr[topIndex] = element;
}

// Pop
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Error: Stack is empty!" << endl;
        return T();
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
