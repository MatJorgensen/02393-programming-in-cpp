#include <iostream>
#include <cmath>

using std::cout;    using std::endl;
using std::cin;     using std::pow;

double pi(int n);

int main()
{
    int n;

    cin >> n;
    cout << pi(n) << endl;

    return 0;
}

double pi(int n)
{
    double approx = 0;

    for (int i = 0; i < n; i++)
        approx += pow(-1.0, i) / (2.0 * i + 1.0);

    return approx * 4.0;
}