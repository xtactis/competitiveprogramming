#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, d; scanf("%d %d %d", &n, &b, &d);
    int ans = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        if (a > b) continue;
        if ((cur += a) > d) {
            cur = 0;
            ++ans;
        }
    }
    printf("%d", ans);
    return 0;
}