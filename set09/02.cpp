#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;    using std::endl;
using std::cin;     using std::vector;

/* prototypes */
int fibonacci(int n);

int main(void)
{
    int i;
    vector<int> vec;

    while (cin >> i)
        vec.push_back(i);

    for (size_t i = 0; i < vec.size(); i++) {
        vec[i] = fibonacci(vec[i]);
        cout << vec[i] << " ";
    }
    cout << endl;
    
    return 0;
}

int fibonacci(int n)
{
    if (n <= 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}