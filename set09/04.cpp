#include <iostream>
#include <string>
#include <algorithm>

using std::cout;    using std::endl;
using std::cin;     using std::string;
using std::min;

/* prototypes */
int levenshtein(string u, string v);

int main(void)
{
    string u, v;

    /* read two words separated by a space */
    getline(cin, u, ' ');
    getline(cin, v);

    cout << levenshtein(u, v) << endl;
    
    return 0;
}

int levenshtein(string u, string v)
{
    if (u.length() == 0) return u.length();
    if (v.length() == 0) return v.length();
    return min({levenshtein(u.substr(1), v) + 1,
                levenshtein(u, v.substr(1)) + 1,
                levenshtein(u.substr(1), v.substr(1)) + (u[0] == v[0] ? 0 : 1)});
}