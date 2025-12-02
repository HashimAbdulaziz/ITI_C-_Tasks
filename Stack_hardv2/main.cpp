#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:

    // Constructor
    template <typename T>
    Stack<T>::Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1; // -1 means empty
    }

    // Destructor
    template <typename T>
    Stack<T>::~Stack() {
        delete[] arr;
    }

    // Add item to top
    template <typename T>
    void Stack<T>::push(T element) {
        if (isFull()) {
            cout << "Error: Stack is full!" << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = element;
    }

    // pop
    template <typename T>
    T Stack<T>::pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return T(); // Return a default value (like 0)
        }
        T poppedValue = arr[topIndex];
        topIndex--;
        return poppedValue;
    }

    //  top
    template <typename T>
    T Stack<T>::peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return T();
        }
        return arr[topIndex];
    }

    template <typename T>
    bool Stack<T>::isEmpty() {
        return topIndex == -1;
    }


    template <typename T>
    bool Stack<T>::isFull() {
        return topIndex == capacity - 1;
    }

};



int main() {

    Stack<int> s1(5);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Top element is: " << myStack.peek() << endl;

    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    if (myStack.isEmpty()) {
        cout << "Stack is now almost empty." << endl;
    }

    return 0;
}
