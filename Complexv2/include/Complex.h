#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // --- Constructor ---
    Complex(double r = 0.0, double i = 0.0);

    // --- Getters and Setters ---
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void seatImag(double i);

    // --- Compound Assignment Operators ---
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // --- Compound Assignment with Scalars ---
    Complex& operator+=(double rhs);
    Complex& operator-=(double rhs);
    Complex& operator*=(double rhs);
    Complex& operator/=(double rhs);

    // --- Unary Operators ---
    Complex operator-() const;
    Complex operator+() const;

    // --- Increment / Decrement Operators  ---
    // Prefix
    Complex& operator++();
    Complex& operator--();
    // Postfix
    Complex operator++(int);
    Complex operator--(int);

    // --- Binary Operators ---
    friend Complex operator+(Complex lhs, const Complex& rhs);
    friend Complex operator-(Complex lhs, const Complex& rhs);
    friend Complex operator*(Complex lhs, const Complex& rhs);
    friend Complex operator/(Complex lhs, const Complex& rhs);

    // --- Comparison Operators ---
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // --- IO Stream Operators (Friends) ---
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

    // --- Utilities ---
    double magnitude() const;
    Complex conjugate() const;
    double phase() const;
};

#endif
