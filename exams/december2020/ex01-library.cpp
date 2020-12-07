#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    int i, j;
    Complex ** matrix = new Complex*[m];
	for (i = 0; i < m; i++) {
		matrix[i] = new Complex[n];
		for (j = 0; j < n; j++)
            matrix[i][j] = c;
    }
    return matrix;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
   int i, j;
   for (i = 0; i < m; i++) {
       for (j = 0; j < n; j++) {
            if (j == n - 1)
                cout << A[i][j].re << (A[i][j].im < 0 ? "" : "+") << A[i][j].im << "i";
            else
                cout << A[i][j].re << (A[i][j].im < 0 ? "" : "+") << A[i][j].im << "i ";
       }
       cout << endl;
   }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    Complex ** matrix = createMatrix(n, n, {0, 0});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                matrix[i][j].re = 1;
        }
    }
    return matrix;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            Complex tmp = {0, 0};
            for (int k = 0; k < n; k++) {
                tmp = add(tmp, mult(A[i][k], B[k][j]));
            }
            C[i][j] = tmp;
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
