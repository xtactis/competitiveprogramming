#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+23;

char s[N], t[N];
bool used[N];

int main() {
    int n; scanf(" %d%s%s", &n, s, t);
    long long ans = 0;
    for (int j = -1, i = 0; i < n; ++i) {
        if (t[i] == '0') continue;
        for (j = max(i, j+1); j < n; ++j) {
            if (s[j] == '1') break;
        }
        if (j == n) {
            printf("-1");
            return 0;
        }
        used[j] = true;
        ans += j-i;
    }
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') continue;
        if (used[i]) continue;
        if (prev != -1) {
            ans += i-prev;
            prev = -1;
        } else {
            prev = i;
        }
    }
    if (prev != -1) {
        printf("-1");
        return 0;
    }
    printf("%lld", ans);
    return 0;
}