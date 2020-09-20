#include <iostream>
#include <vector>

using std::cout;    using std::endl;
using std::cin;     using std::vector;

int main()
{
    int n, scalar_product = 0;
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

    // fill remaining values
    if (a.size() > b.size())
        b.resize(a.size());
    if (b.size() > a.size())
        a.resize(b.size());

    // print scalar product
    typedef vector<int>::size_type vec_sz;

    for (vec_sz i = 0; i < a.size() && i < b.size(); i++)
       scalar_product += a[i] * b[i];
    cout << scalar_product << endl;

    return 0;    
}