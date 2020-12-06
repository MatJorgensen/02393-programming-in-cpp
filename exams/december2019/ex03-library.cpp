#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList() {
	allWords.push_back("121");
	wordsToPalindromeDistance["121"] = 0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"] = 1;
}

//Exercise 3 (a) implement this method
void WordsList::print() {
	typedef vector<int>::size_type vec_sz;
	cout << allWords.size() << " words:";
	for(vec_sz i = 0; i < allWords.size(); i++)
		cout << " " << allWords[i] << " (" << wordsToPalindromeDistance[allWords[i]] << ")";
	cout << endl;
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s) { 
    int distance = 0, l = 0, r = s.length() - 1;
    while (l < r) { 
        if (s[l++] != s[r--]) { 
            distance++;
        } 
    } 
    return distance;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word) {
	allWords.push_back(word);
	wordsToPalindromeDistance[word] = distancePalindrome(word);
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords() {
	int palindromeWords = 0;
	map<string, int>::iterator itr;
	for (itr = wordsToPalindromeDistance.begin(); itr != wordsToPalindromeDistance.end(); itr++) { 
        if (itr->second == 0)
			palindromeWords++;
    } 
	return palindromeWords;
}