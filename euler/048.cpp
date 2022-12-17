#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e10;

long long mul(long long x, long long y) {
    if (y > x) {
        swap(x, y);
    }
    if (x >= 1e9) {
        long long d = x / 32;
        long long r = x % 32;
        long long ret = (x % 32) * y % mod;
        for (int i = 0; i < 32; ++i) {
            ret = (ret + d*y%mod) % mod;
        }
        return ret;
    }
    return x*y%mod;
}

long long binpow(long long b, long long e) {
    if (!e) return 1;
    if (e&1) return mul(b, binpow(b, e-1));
    return binpow(mul(b, b), e/2);
}

int main() {
    long long sum = 0;
    for (int i = 1; i < 1001; ++i) {
        sum = (sum + binpow(i, i)) % mod;
    }
    printf("%lld", sum);

    return 0;
}
