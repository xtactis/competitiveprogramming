#include <bits/stdc++.h>
using namespace std;

const int N = 16;

int a[N], x[N][N], y[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        for (int j = 0; j < a[i]; ++j) {
            scanf("%d %d", &x[i][j], &y[i][j]);
            --x[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        bool cont = false;
        for (int j = 0; j < n; ++j) {
            if (!((1 << j) & i)) continue;
            for (int k = 0; k < a[j]; ++k) {
                if (y[j][k] != ((i >> x[j][k])&1)) cont = true;
            }
        }
        if (!cont) ans = max(ans, __builtin_popcount(i));
    }
    
    printf("%d", ans);
    return 0;
}
