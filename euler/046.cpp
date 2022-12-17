#include <bits/stdc++.h>

using namespace std;

const int n = 10000;
bool isprime[n];

int main() {
    vector<int> primes {2};
    vector<int> composites;
    for (int i = 3; i <= n; i += 2) {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] <= sqrt(i); ++j) {
            if (i % primes[j] == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            primes.push_back(i);
        } else {
            composites.push_back(i);
        }
    }
    for (int c: composites) {
        bool canbemade = false;
        for (int i = 1; i <= n && c-2*i*i > 1; ++i) {
            int p = c-2*i*i;
            bool found = false;
            for (int q: primes) {
                if (p == q) {
                    found = true;
                    break;
                }
            }
            if (found) {
                canbemade = true;
                break;
            }
        }
        if (!canbemade) {
            printf("%d", c);
            break;
        }
    }

    return 0;
}
