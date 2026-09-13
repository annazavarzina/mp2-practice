#include "complex.h"

Complex::Complex() {
    re = 0;
    im = 0;
}
Complex::Complex(double _re, double _im) {
    re = _re;
    im = _im;
}
Complex::Complex(const Complex& c) {
    re = c.re;
    im = c.im;
}
Complex::Complex(Complex&& c) noexcept {
    re = c.re;
    im = c.im;
    c.re = 0;
    c.im = 0;
}
Complex& operator=(const Complex& c) {
    if (this != &c) {
        re = c.re;
        im = c.im;
    }
    return *this;
}

Complex operator+(const Complex& c) const {
    return Complex(re + c.re, im + c.im);
}
Complex operator-(const Complex& c) const {
    return Complex(re - c.re, im - c.im);
}
Complex operator*(const Complex& c) const {
    return Complex(
        re * c.re - im * c.im,
        re * c.im + im * c.re
    );
}
Complex operator/(const Complex& c) const {
    double denominator = c.re * c.re + c.im * c.im;
    return Complex(
        (re * c.re + im * c.im) / denominator,
        (im * c.re - re * c.im) / denominator
    );
}
Complex operator-() const {
    return Complex(-re, -im);
}
bool operator==(const Complex& c) const {
    return re == c.re && im == c.im;
}
bool operator!=(const Complex& c) const {
    return !(*this == c);
};

std::ostream& operator<<(std::ostream& out, const Complex& k) {
    out << k.re;

    if (k.im >= 0)
        out << " + " << k.im << "i";
    else
        out << " - " << -k.im << "i";

    return out;
}
std::istream& operator>>(std::istream& in, Complex& k) {
    cout << "¬ведите действительную часть: ";
    in >> k.re;

    cout << "¬ведите мнимую часть: ";
    in >> k.im;

    return in;
}