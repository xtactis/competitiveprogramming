#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;

int n, m, a, b;
vector<int> g[N];
int lev[N];
set<int> cuts;

int dfs(int u, int pu, int l) {
    lev[u] = l;
    int x = 0, y = l, c = 0;
    for (auto v: g[u]) {
        if (!lev[v]) {
            int t = dfs(v, u, l+1);
            y = min(y, t);
            x |= (l <= t);
            if (u == 0) ++c;
        } else if (v != pu) {
            y = min(y, lev[v]);
        }
    }
    if (u == 0 && c > 1) cuts.insert(u);
    if (u != 0 && x) cuts.insert(u);
    return y;
}

int bio[N];
bool good = 1;
int dfs2(int u, int orig, int shit) {
    bio[u] = 1;
    int ret = 1;
    for (const auto &v: g[u]) {
        if (bio[v]) continue;
        good &= v != shit;
        ret += dfs2(v, orig, shit);
        good |= u == orig;
    }
    return ret*good;
}

void clear() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        lev[i] = 0;
        bio[i] = 0;
    }
    cuts.clear();
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        --a; --b;
        for (int i = 0; i < m; ++i) {
            int u, v; scanf("%d %d", &u, &v);
            g[u-1].push_back(v-1);
            g[v-1].push_back(u-1);
        }
        dfs(0, -1, 1);
        if (cuts.count(a) == 0 && cuts.count(b) == 0) {
            printf("0\n");
            clear();
            continue;
        }
        good = 1;
        long long x = dfs2(a, a, b)-1;
        good = 1;
        for (int i = 0; i < n; ++i) bio[i] = 0;
        long long y = dfs2(b, b, a)-1;
        printf("%lld\n", x*y);
        clear();
    }
    
    return 0;
}