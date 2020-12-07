#include <iostream>
#include <vector>
#include <iomanip> 
#include "ex01-library.h"
using namespace std;

//Exercise 1 (a) Check and correct if necessary
int ** createMatrix(unsigned int n, unsigned int m){
  int ** A = new int *[n];
  for(unsigned int i = 0; i<=n; i++){
    A[i] = new int[n];
  }
}

//Exercise 1 (b) Implement this function
int ** duplicateMatrix(int ** A, unsigned int n, unsigned int m){
  //Put your code here        
}

//Exercise 1 (c) Implement this function
void initMatrix(int ** A, unsigned int n, unsigned int m){
  //Put your code here        
}

//Exercise 1 (d) Implement this function
void deallocateMatrix(int ** A, unsigned int n){
  //Put your code here        
}

//Exercise 1 (e) Implement this function
int ** makeBitonal(int ** A, unsigned int n, unsigned int m,
      int threshold){
  //Put your code here        
}

//Do not modify
void printMatrix(int ** A, unsigned int n, unsigned int m, 
			string description){
  cout<< "Printing: " << description << endl;
  for(unsigned int i = 0; i < n; i++){
    for(unsigned int j = 0; j < m; j++){
      cout << setw(5) << A[i][j] << " ";
    }
    cout << endl;
  }
}