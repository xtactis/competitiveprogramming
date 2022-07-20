#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt[1001] = {};
    for (int p = 10; p <= 1000; ++p) {
        for (int a = 3; a < p; ++a) {
            for (int b = 2; b < a; ++b) {
                double sq = sqrt(a*a-b*b);
                if (sq != round(sq)) continue;
                int c = sq;
                if (c > b || c > a) continue;
                if (a+b+c != p) continue;
                if (b*b+c*c == a*a) ++cnt[p];
            }
        }
    }
    int ans = 0;
    for (int p = 1; p < 1001; ++p) {
        if (cnt[p] > cnt[ans]) ans = p;
    }
    printf("%d %d %d\n", ans, cnt[ans], cnt[120]);
    return 0;
}