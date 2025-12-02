#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <iostream>

class CustomString {
private:
    char* str;
    size_t length;

public:

    CustomString();
    CustomString(const char* val);
    CustomString(const CustomString& other);

    ~CustomString();

    CustomString& operator=(const CustomString& other);
    CustomString operator+(const CustomString& other);
    bool operator==(const CustomString& other);
    char& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& os, const CustomString& obj);
    friend std::istream& operator>>(std::istream& is, CustomString& obj);

    size_t getLength() const;
};

#endif
