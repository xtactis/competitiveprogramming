#include <bits/stdc++.h>

using namespace std;

long long check(long long x) {
    vector<int> primes {17, 13, 11, 7, 5, 3, 2};
    long long X = x;
    for (size_t i = 0; i < primes.size(); ++i) {
        long long cur = x % 1000;
        x /= 10;
        if (cur % primes[i]) return 0;
    }
    return X;
}

long long dfs(long long x, int s) {
    if (s == 0) {
//        printf("%lld\n", x);
        return check(x);
    }
    long long ret = 0;
    x *= 10;
    for (int i = x == 0; i < 10; ++i) {
        if ((s & (1 << i)) == 0) continue;
        ret += dfs(x+i, s ^ (1 << i));
    }
    return ret;
}

int main() {
    int s = (1<<10)-1;
    printf("%lld", dfs(0, s));

    return 0;
}
