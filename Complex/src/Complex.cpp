#include "Complex.h"
#include <cmath>
#include <iostream>

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getters and Setters
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }


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


// Cout <<
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


