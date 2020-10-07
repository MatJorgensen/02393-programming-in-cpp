#include <iostream>

using std::cout;    using std::endl;
using std::cin;

int main()
{
    int n, sum = 0;

    cin >> n;
    // using formula 0 + 2 + ... + n = n/2 * (n/2 + 1)
    cout << n/2 * (n/2 + 1) << endl;

    return 0;
}

