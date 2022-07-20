#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    for (int i = 2; i < 20000000; ++i) {
        int t = i, s = 0;
        while (t) {
            int d = t%10;
            s += d*d*d*d*d;
            if (s > i) break;
            t /= 10;
        }
        if (i == s) ans += i;
    }
    printf("%lld", ans);
    return 0;
}