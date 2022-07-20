#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+23;

vector<int> g[N];
vector<int> input;

bool bio[N];
bool tree;

int dfs(int u, int p = -1) {
    bio[u] = true;
    int ret = 1;
    for (int v: g[u]) {
        if (bio[v]) {
            if (v != p) tree = false;
            continue;
        }
        ret += dfs(v, u);
    }
    return ret;
}

int main() {
    int n; scanf("%d", &n);
    for (int a, b, i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        input.push_back(a);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (int u: input) {
        if (bio[u]) continue;
        tree = true;
        ans += dfs(u);
        if (tree) --ans;
    }
    printf("%d", ans);
    return 0;
}