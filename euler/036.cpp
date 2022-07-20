#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

bool palindrome(int x, int d, int base) {
    vector<int> v;
    for (int i = 0; i < d/2; ++i) {
        v.push_back(x%base);
        x /= base;
    }
    if (d%2) {
        x /= base;
    }
    for (int i = 0; i < d/2; ++i) {
        if (x%base != v.back()) return false;
        v.pop_back();
        x /= base;
    }
    return true;
}

int main() {
    int ans = 0, p = 10, d = 1, p2 = 2, d2 = 1;
    for (int i = 1; i < N; ++i) {
        if (i == p) {
            ++d;
            p *= 10;
        }
        if (i == p2) {
            ++d2;
            p2 *= 2;
        }
        if (palindrome(i, d, 10) && palindrome(i, d2, 2)) {
            ans += i;
        }
    }
    printf("%d\n", ans);
    return 0;
}