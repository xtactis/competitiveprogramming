#include <bits/stdc++.h>
using namespace std;

long long n;

long long calc(long long x) {
    long long ret = x/10;
    for (long long cur = 50; cur < LLONG_MAX/5; cur *= 5) {
        ret += x/cur;
    }
    return ret;
}

int main() {
    cin >> n;
    if (n%2) return !printf("0");
    cout << calc(n);
    return 0;
}
