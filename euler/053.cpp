#include <bits/stdc++.h>

using namespace std;

double comb(int n, int r) {
    double res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n-r+i) / i;
    }
    return res;
}

int main() {
    int ans = 0;
    for (int n = 23; n <= 100; ++n) {
        for (int r = 1; r <= n; ++r) {
            if (comb(n, r) >= 1000000) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
