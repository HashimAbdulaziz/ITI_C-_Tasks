#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor (Default arguments go in the header)
    Complex(double r = 0.0, double i = 0.0);

    // Getters and Setters
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);

    // Compound Assignment Operators
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // Assignment Operators for Scalars (doubles)
    Complex& operator+=(double rhs);
    Complex& operator-=(double rhs);
    Complex& operator*=(double rhs);
    Complex& operator/=(double rhs);

    friend Complex operator+(Complex lhs, const Complex& rhs);
    friend Complex operator-(Complex lhs, const Complex& rhs);
    friend Complex operator*(Complex lhs, const Complex& rhs);
    friend Complex operator/(Complex lhs, const Complex& rhs);

    // Comparison Operators
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;


    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

};

#endif
