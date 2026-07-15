#include <iostream>
#include "Polynom.h"

using namespace std;

void printHeader(const string& title) {
    cout << "\n--- " << title << " ---\n";
}

int main() {
    printHeader("CONSTRUCTORS & STATIC COUNT");

    cout << "Active objects count: " << Polynom::get_count() << "\n\n";

    Polynom p0;
    cout << "p0: " << p0 << "\n";

    Polynom p1(3);
    cout << "p1: " << p1 << "\n";

    double coeff[] = { -3.0, 5.0, 2.0 };
    Polynom p2(3, coeff);
    cout << "p2: " << p2 << "\n";

    Polynom p3 = p2;
    cout << "p3 (copy of p2): " << p3 << "\n";

    cout << "\nActive objects count: " << Polynom::get_count() << "\n";


    printHeader("INDEXING & EVALUATION");

    cout << "p2 original: " << p2 << "\n";
    cout << "p2[1]: " << p2[1] << "\n";

    p2[1] = 9.5;
    cout << "p2 after p2[1] = 9.5: " << p2 << "\n";

    double x = 2.0;
    cout << "p2(" << x << ") = " << p2(x) << "\n";


    printHeader("MATH OPERATIONS (+, -, *)");

    double cA[] = { 1.0, 2.0 };
    double cB[] = { 3.0, 4.0 };
    Polynom A(2, cA);
    Polynom B(2, cB);

    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n\n";

    cout << "A + B = " << (A + B) << "\n";
    cout << "A - B = " << (A - B) << "\n";
    cout << "A * B = " << (A * B) << "\n";


    printHeader("COMPARISONS");

    cout << "A == B ? " << (A == B ? "True" : "False") << "\n";
    cout << "A != B ? " << (A != B ? "True" : "False") << "\n";


    printHeader("INTERACTIVE INPUT");

    int degree;
    cout << "Enter polynomial degree: ";
    cin >> degree;

    Polynom userPoly(degree);
    cout << "Enter " << degree + 1 << " coefficients (from x^" << degree << " down to x^0):\n";
    cin >> userPoly;

    cout << "\nYour polynomial: " << userPoly << "\n";
    cout << "Evaluated at x = 3: " << userPoly(3.0) << "\n";

    return 0;
}