#include <iostream>

using std::cout;    using std::endl;
using std::cin;

int main()
{
    int n, i = 2;

    cin >> n;

    while (i * i <= n) {
        if (n % i == 0) {
            cout << i << " * ";
            n /= i;
        } else
            i++;
    }
    if (n > 1)
        cout << n << endl;

    return 0;
}
