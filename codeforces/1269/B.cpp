#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int a[N], b[N];
map<int, int> h, g;
//~ int a;
//~ int x, y, z;
int n, m, l;
//~ int b, c, d;

bool check(int x, int y) {
    while (x < 0) x+=m;
    while (y < 0) y+=m;
    return x%m == y%m;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", b+i);
    }
    sort(a, a+n);
    sort(b, b+n);
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        bool all = true;
        int x = b[0]-a[i];
        for (int j = 1; j < n; ++j) {
            if (!check(x, b[j]-a[(j+i)%n])) {
                all = false;
                break;
            }
        }
        if (all) {
            while (x < 0) x+=m;
            ans = min(ans, x%m);
        }
    }
    printf("%d", ans);
    return 0;
}