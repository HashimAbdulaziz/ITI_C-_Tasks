#include "Complex.h"
#include <cmath>
#include <iostream>

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getters and Setters
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
void Complex::setReal(double r) { real = r; }
void Complex::seatImag(double i) { imag = i; }

// --- Compound Assignment Operators ---
Complex& Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    this->real -= other.real;
    this->imag -= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double oldReal = this->real;
    this->real = (oldReal * other.real) - (this->imag * other.imag);
    this->imag = (oldReal * other.imag) + (this->imag * other.real);
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = (other.real * other.real) + (other.imag * other.imag);
    if (denominator == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return *this;
    }
    double oldReal = this->real;
    this->real = ((oldReal * other.real) + (this->imag * other.imag)) / denominator;
    this->imag = ((this->imag * other.real) - (oldReal * other.imag)) / denominator;
    return *this;
}

// --- Compound Assignment with Scalars ---
Complex& Complex::operator+=(double rhs) {
    this->real += rhs;
    return *this;
}

Complex& Complex::operator-=(double rhs) {
    this->real -= rhs;
    return *this;
}

Complex& Complex::operator*=(double rhs) {
    this->real *= rhs;
    this->imag *= rhs;
    return *this;
}

Complex& Complex::operator/=(double rhs) {
    if (rhs == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return *this;
    }
    this->real /= rhs;
    this->imag /= rhs;
    return *this;
}

// --- Unary Operators ---

// Unary Minus (Negates both parts)
Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

// Unary Plus (Returns copy)
Complex Complex::operator+() const {
    return *this;
}

// --- Increment / Decrement Operators ---

// Prefix Increment (++c)
// Increases Real part by 1, returns reference to self
Complex& Complex::operator++() {
    this->real += 1.0;
    return *this;
}

// Prefix Decrement (--c)
Complex& Complex::operator--() {
    this->real -= 1.0;
    return *this;
}

// Postfix Increment (c++)
// Makes a copy, increments self, returns the copy
Complex Complex::operator++(int) {
    Complex temp = *this;
    ++(*this); // Call prefix operator
    return temp;
}

// Postfix Decrement (c--)
Complex Complex::operator--(int) {
    Complex temp = *this;
    --(*this); // Call prefix operator
    return temp;
}

// --- Binary Operators ---
Complex operator+(Complex lhs, const Complex& rhs) {
    lhs += rhs;
    return lhs;
}

Complex operator-(Complex lhs, const Complex& rhs) {
    lhs -= rhs;
    return lhs;
}

Complex operator*(Complex lhs, const Complex& rhs) {
    lhs *= rhs;
    return lhs;
}

Complex operator/(Complex lhs, const Complex& rhs) {
    lhs /= rhs;
    return lhs;
}

// --- Comparison Operators ---
bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// --- IO Stream Operators ---
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    } else {
        os << " - " << -c.imag << "i";
    }
    os << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    // Simple input format: reads two numbers.
    // Example input: 3 4
    is >> c.real >> c.imag;
    return is;
}

// --- Utilities ---
double Complex::magnitude() const {
    return std::sqrt(real * real + imag * imag);
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

double Complex::phase() const {
    return std::atan2(imag, real);
}
