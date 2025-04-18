#include "Polynomial.h"
using namespace std;

double* InputPolynomial(int degree) {
    double* a;
    a = (double*)malloc(degree * sizeof(double));

    int number;
    number = degree + 1;

    cout << "Введите " << number << " коэффициента: " << endl;

    for (int i = 0; i <= degree; ++i) {
        cout << "Введите " << i + 1 << "-й коэффициент: ";
        cin >> a[i];
    }
    return a;
    free(a);
}

void OutputPolynomial(const double* a, int degree) {
    bool flag = true;
    for (int i = degree; i >= 0; --i) {
        if (a[i] != 0) {
            if (!flag) {
                cout << " + ";
            }
            cout << a[i] << "x^" << i;
            flag = false;
        }
    }
}

double* AdditionOfPolynomials(double* a, double* b) {
    double* result;
    int max_degree;

    if (sizeof(a) >= sizeof(b))
        max_degree = sizeof(a);
    else if (sizeof(a) < sizeof(b))
        max_degree = sizeof(b);

    result = (double*)malloc(max_degree * sizeof(double));

    for (int i = 0; i < max_degree; ++i) {
        double coeff1 = (i < sizeof(a)) ? a[i] : 0;
        double coeff2 = (i < sizeof(b)) ? b[i] : 0;
        result[i] = coeff1 + coeff2;;
    }

    return result;
}