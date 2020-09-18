#include <iostream>

using std::cout;    using std::endl;
using std::cin;

int main()
{
    int n;

    cin >> n;
    // using formula 1 + 2 + ... + n = n * (n + 1)/2
    cout << n * (n + 1) / 2 << endl;

    return 0;
}