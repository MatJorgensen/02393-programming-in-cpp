#include <iostream>
#include <sstream>

using std::cout;    using std::string;
using std::cin;     using std::stringstream;
using std::endl;    


class fraction {

    private:
        // Internal representation of a fraction as two integers
        int num;
        int denom;

    public:
        // Class constructor
        fraction(int n, int d)
        {
            num = n;
            denom = d;
        }

        // Methods to update the fraction
        void add(fraction f) 
        {
            num = num * f.denom  + f.num * denom;
            denom *= f.denom;
        }

        void mult(fraction f)
        {
            num *= f.num;
            denom *= f.denom;
        }

        void div(fraction f)
        {
            num *= f.denom;
            denom *= f.num;
        }

        // Reduce and display method
        void display(void)
        {
            int m = num, n = denom, r;

            while (n != 0) {
                r = m % n;
                m = n;
                n = r;
            }

            cout << num / m << " / " << denom / m << endl;
        }
};


int main()
{   
    string s;
    int n1, d1, n2, d2;
    char op;

    while (getline(cin, s)) {
        stringstream ss(s);

        // read values for f1
        ss >> n1;
        ss.ignore(1, '/');
        ss >> d1;
        ss.ignore();

        // read operator
        ss >> op;
        if (op == 'd')
            ss.ignore(2);

        // read values for f2
        ss >> n2;
        ss.ignore(1, '/');
        ss >> d2;
        ss.ignore();

        // declare object of class 'fraction'
        fraction f1(n1, d1), f2(n2, d2);

        switch (op)
        {
            case '+':
                f1.add(f2);
                break;
            case '*':
                f1.mult(f2);
                break;
            case 'd':
                f1.div(f2);
                break;
            default:
                break;
        }

        f1.display();
    }

    return 0;
}