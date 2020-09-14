#include <iostream>

using std::cout;    using std::endl;
using std::cin;

int main()
{
    int n, sum = 0;

    cin >> n;
    for (int i = 0; i <= n; i += 2)
        sum += i;
    cout << sum << endl;

    return 0;
}