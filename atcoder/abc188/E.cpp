#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+23;

int a[N];
vector<int> g[N];

int ms[N];
int maxs(int u) {
    int &ret = ms[u];
    if (ret != -1) return ret;
    ret = a[u];
    for (int v: g[u]) {
        ret = max(ret, maxs(v));
    }
    return ret;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    for (int u, v, i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        g[--u].push_back(--v);
    }
    memset(ms, -1, sizeof(ms));
    int ans = -2e9;
    for (int i = 0; i < n; ++i) {
        for (int v: g[i]) {
            ans = max(ans, maxs(v)-a[i]);
        }
    }
    printf("%d", ans);
    return 0;
}