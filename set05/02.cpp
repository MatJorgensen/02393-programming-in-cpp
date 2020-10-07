#include <iostream>
#include <vector>

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

    // print datasets
    typedef vector<int>::size_type vec_sz;

    for (vec_sz i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size())
            cout << a[i] << " ";
        if (i < b.size())
            cout << b[i] << " ";
    }
    cout << endl;

    return 0;    
}