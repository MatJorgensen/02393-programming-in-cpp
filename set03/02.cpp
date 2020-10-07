#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using std::cout;    using std::endl;
using std::cin;     using std::max_element;
using std::vector;     

int main()
{
    int l, n, k, m, x;

    cin >> l >> n;

    vector<int> numbers;

    // store numbers and compute histogram params
    for (int i = 0; i < n; i++) {
        cin >> x;
        numbers.push_back(x);
    }

    m = *max_element(numbers.begin(), numbers.end());
    k = ceil(static_cast<float>(m) / static_cast<float>(l));

    // initialize histogram
    vector<int> histogram(l, 0);

    // populate histogram
    typedef vector<int>::size_type vec_sz;

    for (vec_sz i = 0; i < numbers.size(); i++)
        histogram[numbers[i] / k]++;
    if (m % l == 0) 
        histogram[l - 1]++;

    // display histogram
    for (vec_sz i = 0; i < histogram.size(); i++)
        cout << i * k << ": " << histogram[i] << endl;

    return 0;
}