#include <iostream>
#include <set>

using std::cout;    using std::multiset;
using std::cin;     using std::string;
using std::endl;

int main()
{
    double n;
    string str;
    multiset<double> bag;

    while (cin >> str) {
        if (str == "add") {
            cin >> n;
            bag.insert(n);
        } else if (str == "del") {
            cin >> n;
            const auto itr = bag.find(n);
            if (itr != bag.end())
                bag.erase(itr);
        } else if (str == "qry") {
            cin >> n;
            if (bag.find(n) != bag.end())
                cout << 'T';
            else 
                cout << 'F';
        } else {
            cout << endl;
            return 0;
        }   
    }
}