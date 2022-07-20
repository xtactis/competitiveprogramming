#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

bool prime[N];

int main() {
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) continue;
        primes.push_back(i);
        if (primes.size() == 10001) break;
        for (int j = i + i; j <= N; j += i) {
            prime[j] = true;
        }
    }
    printf("%d", primes[10000]);
    return 0;
}