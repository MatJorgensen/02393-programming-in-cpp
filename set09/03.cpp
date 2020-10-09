#include <iostream>
#include <vector>

using std::cout;    using std::endl;
using std::cin;     using std::vector;

/* prototypes */
void palindrome(vector<int> &vec, int l, int r);

int main(void)
{
    int i;
    vector<int> vec;

    while(cin >> i)
        vec.push_back(i);

    palindrome(vec, 0, vec.size());
    
    return 0;
}

void palindrome(vector<int> &vec, int front, int back)
{
    if (front >= back) {
        cout << "yes" << endl;
        return;
    }

    if (vec[front] == vec[back - 1])
        palindrome(vec, front + 1, back - 1);
    else {
        cout << "no" << endl;
        return;
    }
}