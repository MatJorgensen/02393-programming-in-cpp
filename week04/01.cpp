#include <iostream>
#include <set>

using std::cout;    using std::set;
using std::cin;     using std::string;
using std::endl;

enum commands {
    invalid,
    add,
    del,
    qry,
    quit
};

// prototypes 
commands resolve_cmd(string const& str);

int main()
{
    int n;
    string str;
    set<int> bag;

    while(cin >> str) {
        switch (resolve_cmd(str)) {
            case add:
                cin >> n;
                bag.insert(n);
                break;
            case del:
                cin >> n;
                bag.erase(n);
                break;
            case qry:
                cin >> n;
                if (bag.find(n) != bag.end())
                    cout << 'T';
                else 
                    cout << 'F';
                break;
            case quit:
                cout << endl;
                return 0;
            default:
                break;
        }
    }

    return 0;
}

commands resolve_cmd(string const& str) 
{
    if (str == "add") return add;
    if (str == "del") return del;
    if (str == "qry") return qry;
    if (str == "quit") return quit;

    return invalid;
}