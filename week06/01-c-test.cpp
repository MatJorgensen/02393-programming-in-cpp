#include <iostream>
#include <vector>

using std::cout;    using std::endl;
using std::cin;     using std::vector;

void primes(int n, int s[]);
vector<int> generate_prime_factors(int n);

int main() {
    vector<int> powers;
    int n;

    cin >> n;
    powers = generate_prime_factors(n);

    for (size_t i = 0; i < powers.size(); i++)
        cout << powers[i] << "  ";
    cout << endl;

    return 0;
}


void primes(int n, int s[]) {
    vector<bool> prime(n + 1, false);

    //int s[n] = {0};

    for (int i = 2; i <= n; i += 2)
        s[i] = 2;
    for (long long i = 3; i <= n; i += 2) {
        if (prime[i] == false) {
            s[i] = i;
            for (long long j = i; j * i <= n; j += 2) {
                if (prime[i*j] == false) {
                    prime[i*j] = true;
                    s[i*j] = i;
                }
            }
        }
    }
}


vector<int> generate_prime_factors(int n) {
    vector<int> powers;
    int s[n+1];
    primes(n, s);
    int prime = s[n];
    int power = 1;
    while (n > 1) {
        n /= s[n];
        if (prime == s[n]) {
            power++;
            continue;
        }
        powers.push_back(power);
        
        prime = s[n];
        power = 1;
    }

    return powers;
}

