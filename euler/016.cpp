#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> v;
    v.push_back(1);
    const long long MAX = 1e18;
    for (int i = 0; i < 1000; ++i) {
        long long carry = 0;
        for (long long &e: v) {
            e = e*2+carry;
            carry = 0;
            if (e > MAX) {
                carry = e/MAX;
                e %= MAX;
            }
        }
        if (carry) {
            v.push_back(carry);
        }
    }
    long long ans = 0;
    for (long long e: v) {
        while (e) {
            ans += e%10;
            e /= 10;
        }
    }
    printf("%lld", ans);
    return 0;
}