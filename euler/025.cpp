#include <bits/stdc++.h>
using namespace std;

int digits(long long x) {
    for (int i = 1e8, ret = 9; i > 0; i /= 10, --ret) {
        if (x > i) return ret;
    }
    return 1;
}

int digits(const vector<long long> &v) {
    int ret = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        if (i < v.size()-1) ret += 9;
        else ret += digits(v[i]);
    }
    return ret;
}

void print(const vector<long long> &v) {
    printf("%lld", v.back());
    for (int j = v.size()-2; j >= 0; --j) {
        printf("%09lld", v[j]);
    }
}

int main() {
    vector<long long> a = {1}, b = {1}, c;
    int i = 1;
    const long long MAX = 1e9;
    for (; digits(a) < 1000; ++i) {
        //printf(" %d\n", digits(a));
        c = a;
        a = b;
        long long carry = 0;
        for (int j = 0; j < b.size(); ++j) {
            b[j] += (j < c.size()?c[j]:0) + carry;
            carry = 0;
            if (b[j] >= MAX) {
                carry = b[j] / MAX;
                b[j] %= MAX;
            }
        }
        if (carry) b.push_back(carry);
    }
    printf("%d", i);
    return 0;
}