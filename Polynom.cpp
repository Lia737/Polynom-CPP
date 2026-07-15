#include <iostream>
#include <cassert>
#include "Polynom.h"

using namespace std;

int Polynom::count = 0;

// Default constructor
Polynom::Polynom() {
    m_arr = new double[1];
    m_arr[0] = 0;
    m_degree = 0;
    count++;
}

// Degree constructor (initializes all coefficients to 1)
Polynom::Polynom(int degree) : m_degree(degree > 0 ? degree : 0) {
    m_arr = new double[m_degree + 1];
    for (int i = m_degree; i >= 0; i--) {
        m_arr[i] = 1;
    }
    count++;
}

// Array constructor
Polynom::Polynom(int n, double* arr) : m_degree(n - 1 > 0 ? n - 1 : 0) {
    m_arr = new double[m_degree + 1];
    for (int i = m_degree; i >= 0; i--) {
        m_arr[i] = arr[i];
    }
    count++;
}

//  Copy constructor 
Polynom::Polynom(const Polynom& ob) : m_degree(ob.m_degree) {
    m_arr = new double[m_degree + 1];
    for (int i = 0; i <= m_degree; i++) {
        m_arr[i] = ob.m_arr[i];
    }
    count++;
}

// Destructor
Polynom::~Polynom() {
    delete[] m_arr;
    m_arr = nullptr;
    count--;
}

int Polynom::get_count() {
    return count;
}

// Assignment operator
Polynom& Polynom::operator=(const Polynom& ob) {
    if (this != &ob) {
        if (m_degree != ob.m_degree) {
            delete[] m_arr;
            m_degree = ob.m_degree;
            m_arr = new double[m_degree + 1];
        }
        for (int i = 0; i <= m_degree; i++) {
            m_arr[i] = ob.m_arr[i];
        }
    }
    return *this;
}

// Non-const index operator
double& Polynom::operator[](int a) {
    assert(a >= 0 && a <= m_degree);
    return m_arr[a];
}

// Const index operator
double Polynom::operator[](int a) const {
    assert(a >= 0 && a <= m_degree);
    return m_arr[a];
}

// Evaluate using direct calculation
double Polynom::operator()(double x) const {
    double res = 0;
    for (int i = 0; i <= m_degree; i++) {
        double xi = 1;
        for (int j = 1; j <= i; j++) {
            xi *= x;
        }
        res += m_arr[i] * xi;
    }
    return res;
}

// >>operator
istream& operator>>(istream& in, Polynom& ob) {
    for (int i = ob.m_degree; i >= 0; i--) {
        in >> ob.m_arr[i];
    }
    return in;
}

// << operator
ostream& operator<<(ostream& out, const Polynom& ob) {
    bool firstTerm = true;
    for (int i = ob.m_degree; i >= 0; i--) {
        if (ob.m_arr[i] != 0) {
            // Sign/Formatting for non-first term
            if (!firstTerm && ob.m_arr[i] > 0) {
                out << "+";
            }

            if (i == 0) {
                // Constant term
                out << ob.m_arr[i];
            }
            else {
                // Print coefficients
                if (ob.m_arr[i] == -1) {
                    out << "-";
                }
                else if (ob.m_arr[i] != 1) {
                    out << ob.m_arr[i];
                }

                // Print variables and exponents
                out << "x";
                if (i > 1) {
                    out << "^" << i;
                }
            }
            firstTerm = false;
        }
    }
    if (firstTerm) {
        out << 0;
    }
    return out;
}

bool Polynom::operator==(const Polynom& ob) const {
    if (this != &ob) {
        if (m_degree != ob.m_degree) return false;
        for (int i = 0; i <= m_degree; i++) {
            if (m_arr[i] != ob.m_arr[i]) {
                return false;
            }
        }
    }
    return true;
}

bool Polynom::operator!=(const Polynom& ob) const {
    return !(*this == ob);
}

Polynom Polynom::operator+(const Polynom& ob) const {
    int max_degree = m_degree > ob.m_degree ? m_degree : ob.m_degree;
    int min_degree = m_degree < ob.m_degree ? m_degree : ob.m_degree;
    Polynom res(max_degree);

    for (int i = 0; i <= min_degree; i++) {
        res.m_arr[i] = m_arr[i] + ob.m_arr[i];
    }
    if (m_degree > ob.m_degree) {
        for (int i = ob.m_degree + 1; i <= m_degree; i++) {
            res.m_arr[i] = m_arr[i];
        }
    }
    else if (m_degree < ob.m_degree) {
        for (int i = m_degree + 1; i <= ob.m_degree; i++) {
            res.m_arr[i] = ob.m_arr[i];
        }
    }
    // Removed duplicate count++ (handled by constructor)
    return res;
}

Polynom Polynom::operator-(const Polynom& ob) const {
    int max_degree = m_degree > ob.m_degree ? m_degree : ob.m_degree;
    int min_degree = m_degree < ob.m_degree ? m_degree : ob.m_degree;
    Polynom res(max_degree);

    for (int i = 0; i <= min_degree; i++) {
        res.m_arr[i] = m_arr[i] - ob.m_arr[i];
    }
    if (m_degree > ob.m_degree) {
        for (int i = ob.m_degree + 1; i <= m_degree; i++) {
            res.m_arr[i] = m_arr[i];
        }
    }
    else if (m_degree < ob.m_degree) {
        for (int i = m_degree + 1; i <= ob.m_degree; i++) {
            res.m_arr[i] = -ob.m_arr[i];
        }
    }
    // Removed duplicate count++ (handled by constructor)
    return res;
}

// [FIX] Corrected nested loops and array variable typo
Polynom Polynom::operator*(const Polynom& ob) const {
    Polynom res(m_degree + ob.m_degree);
    for (int i = 0; i <= res.m_degree; i++) {
        res.m_arr[i] = 0;
    }
    for (int i = 0; i <= m_degree; i++) {
        for (int j = 0; j <= ob.m_degree; j++) {
            res.m_arr[i + j] += m_arr[i] * ob.m_arr[j]; // Corrected index target
        }
    }
    return res;
}