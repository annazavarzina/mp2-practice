#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

struct Complex
{
    double re;
    double im;

    Complex();
    Complex(double _re, double _im);
    Complex(const Complex& c);
    Complex(Complex&& c) noexcept;
    ~Complex() {}

    Complex& operator=(const Complex& c);

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex operator-() const;

    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;

    friend std::ostream& operator<<(std::ostream& out, const Complex& k);
    friend std::istream& operator>>(std::istream& in, Complex& k);
};

#endif