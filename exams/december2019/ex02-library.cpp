#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n) {
	if (n < 0)
		return "";
	else 
		return s[n] + reverse(s, n - 1);
}

//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2) {
	if (n1 >= n2)
		return true;
	if (s[n1] == s[n2])
		return isPalindrome(s, n1 + 1, n2 - 1);
	else
		return false;
	
}

//Exercise 2 (c) Implement this function
int distancePalindrome(string s, int n1, int n2) {
	if (n1 >= n2)
		return 0;
	else if (s[n1] != s[n2])
		return 1 + distancePalindrome(s, n1 + 1, n2 - 1);
	else
		return distancePalindrome(s, n1 + 1, n2 - 1);
}