#ifndef STACK_H
#define STACK_H
#include <iostream>


class Stack {
private:
    int capacity;
    int* arr;
    int tos;

public:
    Stack(int size);
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    void push(int value);
    int pop();

    int top() const;
    bool empty() const;
    int size() const;

    // Display operator (only declaration here)
    friend std::ostream& operator<<(std::ostream& out, const Stack& s);

    ~Stack();
};


#endif // STACK_H
