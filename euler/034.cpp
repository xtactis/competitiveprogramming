#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int main() {
    int ans = 0;
    int f[10];
    f[0] = 1;
    for (int i = 1; i < 10; ++i) {
        f[i] = f[i-1]*i;
    }
    for (int i = 10; i < N; ++i) {
        int t = i, cur = 0;
        while (t) {
            cur += f[t%10];
            t /= 10;
        }
        if (cur == i) ans += i;
    }
    printf("%d", ans);
    return 0;
}