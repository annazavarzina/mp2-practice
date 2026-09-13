#include <iostream>
#include "complex.h"
using namespace std;

int main() {

    Complex a(2, 3);
    Complex b(4, 5);

    Complex c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    c = a + b;
    cout << "a + b = " << c << endl;

    c = a - b;
    cout << "a - b = " << c << endl;

    c = a * b;
    cout << "a * b = " << c << endl;

    c = a / b;
    cout << "a / b = " << c << endl;

    cout << "-a = " << -a << endl;

    cout << "a == b: " << (a == b) << endl;

    Complex d = a;
    cout << "d = " << d << endl;

	return 0;
}