#include "Stack.h"

Stack::Stack(int capacity): capacity(capacity), tos(-1) {
    arr = new int[capacity];
}

void Stack::push(int value) {
    // Check overflow
    if (tos == capacity - 1) {
        std::cerr << "Stack overflow! Cannot push.\n";
        return;
    }

    // increment tos
    ++tos;

    // Store the value
    arr[tos] = value;
}


int Stack::pop() {
    // Check underflow
    if (tos == -1) {
        std::cerr << "Stack underflow! Cannot pop.\n";
        return -1; // or throw an exception
    }

    // Get the top value
    int value = arr[tos];

    // Decrement the top index
    --tos;

    return value;
}


int Stack::top() const {
    if (tos == -1) {
        std::cerr << "Stack is empty! No top element.\n";
        return -1; // or throw exception if you want
    }
    return arr[tos];
}


bool Stack::empty() const {
    return tos == -1;
}

int Stack::size() const {
    return tos + 1;
}


std::ostream& operator<<(std::ostream& out, const Stack& s) {
    out << "[ ";
    for (int i = 0; i <= s.tos; ++i) {
        out << s.arr[i] << ' ';
    }
    out << "]";
    return out;
}


// --- Copy Constructor ---
/* Note: if you didn't impliment this copy constructoat
   and used the default the array will be the same in both
   when deleting one the other will points to nothing  */
Stack::Stack(const Stack& other) : capacity(other.capacity), tos(other.tos){
    // allocate new memory
    arr = new int[capacity];

    // copy all elements
    for (int i = 0; i <= tos; ++i) {
        arr[i] = other.arr[i];
    }
}


// --- Copy Assignment Operator ---
Stack& Stack::operator=(const Stack& other) {
    // check self-assignment
    if (this == &other)
        return *this;

    // Delete old memory
    delete[] arr;

    // Copy capacity and tos
    capacity = other.capacity;
    tos = other.tos;

    // Allocate new memory
    arr = new int[capacity];

    // Copy elements
    for (int i = 0; i <= tos; ++i) {
        arr[i] = other.arr[i];
    }

    return *this;  // return self-reference
}

Stack::~Stack() {
    delete[] arr;
}
