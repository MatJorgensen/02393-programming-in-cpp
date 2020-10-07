#include <iostream> 
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;    using std::endl;
using std::cin;     using std::map;
using std::vector;  using std::pow;
using std::transform;
using std::plus;

map<int, int> generate_prime_map(int n);
vector<int> factorize(int n);

class fraction {

    private:
        // Internal representation of a fraction as two integers
        vector<int> num;
        vector<int> denom;
        vector<int> primes = {2};

        // return vector of prime factors of 'n'
        vector<int> factorize(int n)
        {
            vector<int> prime_factors;
            int i = 2;

            while (i * i <= n) {
                if (n % i == 0) {
                    prime_factors.push_back(i);
                    n /= i;
                } else
                    i++;
            }
            if (n > 1)
                prime_factors.push_back(n);

            return prime_factors;
        }

        // use sieve of eratosthenes to generate all primes up to 'n'
        map<int, int> generate_prime_map(int n)
        {
            map<int, int> primes;
            int arr[n] = {0};

            for (long long i = 2; i < n; i++)
                for (long long j = i * i; j < n; j += i)
                    arr[j - 1] = 1;

            for (int i = 2; i < n; i++)
                if (arr[i - 1] == 0)
                    primes[i] = 0;

            return primes;
        }

        // convert an integer to exponent vector
        vector<int> int_to_exponent_vector(int n) {
            map<int, int> prime_map;
            vector<int> key, value, prime_factors;
            
            prime_factors = factorize(n);
            prime_map = generate_prime_map(prime_factors.back());

            for (size_t i = 0; i < prime_factors.size(); i++) {
                prime_map[prime_factors[i]]++;
            }
            
            for (map<int, int>::iterator it = prime_map.begin(); it != prime_map.end(); it++) {
                key.push_back(it->first);
                value.push_back(it->second);
            }

            if (primes.size() < key.size())
                primes = key;

            return value;
        }


    public:
        // Class constructor
        fraction(int n, int d)
        {
            num = int_to_exponent_vector(n);
            denom = int_to_exponent_vector(d);
        }

        /*
        // Methods to update the fraction
        void add(fraction f) 
        {
            num = num * f.denom  + f.num * denom;
            denom *= f.denom;
        }
        */
        void mult(fraction f)
        {
            // fetch lookup primes
            if (f.primes.size() > primes.size())
                primes = f.primes;

            // resize arrays
            if (num.size() > f.num.size())
                f.num.resize(num.size());
            else if (f.num.size() > num.size())
                num.resize(f.num.size());

            if (denom.size() > f.denom.size())
                f.denom.resize(denom.size());
            else if (f.denom.size() > denom.size())
                denom.resize(f.denom.size());

            for (size_t i = 0; i < num.size(); i++)
                num[i] += f.num[i];

            for (size_t i = 0; i < denom.size(); i++)
                denom[i] += f.denom[i];
        }

        void div(fraction f)
        {
            // fetch lookup primes
            if (f.primes.size() > primes.size())
                primes = f.primes;

            // resize arrays
            if (num.size() > f.num.size())
                f.num.resize(num.size());
            else if (f.num.size() > num.size())
                num.resize(f.num.size());

            if (denom.size() > f.denom.size())
                f.denom.resize(denom.size());
            else if (f.denom.size() > denom.size())
                denom.resize(f.denom.size());

            for (size_t i = 0; i < num.size(); i++)
                if (num[i] - f.num[i] >= 0)
                    num[i] += f.denom[i];

            for (size_t i = 0; i < denom.size(); i++)
                if (denom[i] - f.denom[i] >= 0)
                    denom[i] += f.num[i];
        }
        

        // Reduce and display method
        void display(void)
        {
            
            int out_num = 1, out_denom = 1;

            // compute num
            for (size_t i = 0; i < num.size(); i++) 
                if (num[i] != 0)
                    out_num *= pow(primes[i], num[i]);

            // compute denom
            for (size_t i = 0; i < denom.size(); i++) 
                if (denom[i] != 0)
                    out_denom *= pow(primes[i], denom[i]);

            // reduce fraction
            int m = out_num, n = out_denom, r;

            while (n != 0) {
                r = m % n;
                m = n;
                n = r;
            }

            cout << out_num / m << " / " << out_denom / m << endl;
            
        }

};

int main() 
{ 
    fraction f1(2, 50000), f2(2, 50000); //(15340, 137200);
    f1.div(f2);
    f1.display();

    return 0; 
} 