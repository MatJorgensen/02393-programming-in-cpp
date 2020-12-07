#include <iostream>

#include <vector>

#include <iomanip>

#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Check and correct if necessary
unsigned int ** createMatrix(int n, int m) {
	int r, c;
	unsigned int ** A = new unsigned int * [n];
	for (r = 0; r < n; r++) {
		A[r] = new unsigned int[m];
	}
    return A;
}

void deallocateMatrix(unsigned int ** A, int n) {
    int r;
    for (r = 0; r < n; r++) {
        delete[] A[r];
    }
    delete[] A;
}

//Exercise 1 (c) Implement this function
void fillWhite(unsigned int ** A, int n, int m) {
    int r, c;
    for (r = 0; r < n; r++) {
        for (c = 0; c < m; c++) {
            A[r][c] = 255;
        }
    }
}

//Exercise 1 (d) Implement this function
void lighten(unsigned int ** A, int n, int m) {
    int r, c;
    for (r = 0; r < n; r++) {
        for (c = 0; c < m; c++) {
            if (A[r][c] < 255)
                A[r][c]++;
        }
    }
}

//Exercise 1 (e) Implement this function
void darken(unsigned int ** A, int n, int m) {
    int r, c;
    for (r = 0; r < n; r++) {
        for (c = 0; c < m; c++) {
            if (A[r][c] > 0)
                A[r][c]--;
        }
    }
}

//Do not modify
void printMatrix(unsigned int ** A, int n, int m,
    string description) {
    cout << "Printing: " << description << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << A[i][j] << " ";
        }
        cout << endl;
    }
}