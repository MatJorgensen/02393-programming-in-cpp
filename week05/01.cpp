#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;    using std::endl;
using std::cin;     using std::vector;

int main()
{
    int n;
    char ch;
    vector<int> a, b;

    // read datasets
    while (cin >> ch) {
        if (ch == 'a') {
            cin >> n;
            a.push_back(n);
        } else if (ch == 'b') {
            cin >> n;
            b.push_back(n);
        } else {
            break;
        }
    }

    // sort datasets
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // print datasets
    typedef vector<int>::size_type vec_sz;

    for (vec_sz i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    for (vec_sz i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;    
}