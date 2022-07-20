#include <bits/stdc++.h>
using namespace std;

const int N = 2.5e5+25;

int n, m; 

long long fact[N];

inline long long mul(long long x, long long y) {
    return (x * y) % m;
}

inline long long add(long long x, long long y) {
    return (x + y) % m;
}

int main() {
    cin >> n >> m;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i-1]*i)%m;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        // for dists 0 to n-1
        ans = add(ans, mul(n-i, mul(fact[i+1], mul(fact[n-i-1], n-i))));
    }
    cout << ans;
    return 0;
}