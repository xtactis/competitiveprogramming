#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+34;

int g[N];
int h[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ++h[x];
        ++g[x];
    }
    int mi = 0;
    for (int i = 1; i <= n; ++i) {
        if (!h[i]) continue;
        h[i] = h[i+1] = h[i+2] = 0;
        ++mi;
    }
    int ma = 0;
    int sum = 0, cnt = 0;
    int start = -1;
    for (int i = 1; i <= n+5; ++i) {
        if (g[i]) {
            if (!cnt) start = i;
            ++cnt;
            sum += g[i];
        } else {
            if (!cnt) continue;
            int x = sum-cnt;
            ma += cnt;
            if (x == 1) {
                ma += x;
                if (g[start-1]) g[i] = 1;
            } else if (x >= 2) {
                x = 2;
                if (g[start-1]) x = 1;
                g[start-1] = 1;
                g[i] = 1;
                ma += x;
            }
            sum = 0; cnt = 0;
        }
    }
    printf("%d %d", mi, ma);
    return 0;
}