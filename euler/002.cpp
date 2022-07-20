#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    for (int a = 0, b = 1, c; a < 4000000; c = b, b += a, a = c) {
        if (a & 1) continue;
        ans += a;
    }
    printf("%lld", ans);
    return 0;
}