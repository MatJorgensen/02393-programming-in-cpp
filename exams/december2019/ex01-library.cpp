#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	int r, c;
	cell ** board = new cell*[n];
	for (r = 0; r < n; r++) {
		board[r] = new cell[n];
		for (c = 0; c < n; c++) {
			board[r][c].color = computeColor(r, c);
			if (r < 3 && board[r][c].color == dark)
				board[r][c].status = blackPiece;
			else if (r >= n - 3 && board[r][c].color == dark)
				board[r][c].status = whitePiece;
			else 
				board[r][c].status = emptyC;
		}
	}
	return board;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n) {
	int r, c;
	cell ** board = new cell*[n];
	for (r = 0; r < n; r++) {
		board[r] = new cell[n];
		for (c = 0; c < n; c++) {
			board[r][c] = A[r][c];
		}
	}
	return board;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A, int n, int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) {
		return false;
	}

	int toc = 0;
	int tor = 0;

	if (A[r][c].status == blackPiece) {
		tor = r + 1;
		toc = c - 1;
	} else if (A[r][c].status = whitePiece) {
		tor = r - 1;
		toc = c + 1;
	} else {
		return false;
	}
	if (tor < 0 || tor >= n || toc < 0 || toc >= n) {
		return false;
	}
	if (A[tor][toc].status != emptyC) {
		return false;
	}
	cellStatus status = A[r][c].status;
	A[r][c].status = emptyC;
	A[tor][toc].status = status;

	return true;
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) {
		return false;
	}

	int toc = 0;
	int tor = 0;

	if (A[r][c].status == blackPiece) {
		tor = r + 1;
		toc = c + 1;
	} else if (A[r][c].status = whitePiece) {
		tor = r - 1;
		toc = c - 1;
	} else {
		return false;
	}
	if (tor < 0 || tor >= n || toc < 0 || toc >= n) {
		return false;
	}
	if (A[tor][toc].status != emptyC) {
		return false;
	}
	cellStatus status = A[r][c].status;
	A[r][c].status = emptyC;
	A[tor][toc].status = status;

	return true;
}

// Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
