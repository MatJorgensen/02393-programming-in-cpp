#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;    using std::vector;
using std::cin;     using std::swap;
using std::endl;

/* prototypes */
void reverse(vector<int> &vec, int front, int back);

int main(void)
{
    int i;
    vector<int> vec;

    while (cin >> i)
        vec.push_back(i);

    reverse(vec, 0, vec.size());

    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    
    return 0;
}

void reverse(vector<int> &vec, int front, int back)
{
    if (front >= back) return;
    swap(vec[front], vec[back - 1]);
    reverse(vec, front + 1, back - 1);  
}