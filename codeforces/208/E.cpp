#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

struct LCA {
    vector<int> height, segtree, euler, first, vh[N], vhpos;
    vector<int> color;
    LCA(const vector<vector<int>> &g, int n) {
        height.resize(n);
        first.resize(n);
        vhpos.resize(n);
        euler.reserve(4*n);
        color.assign(n, 0);
        int c = 1;
        for (int i = 0; i < n; ++i) {
            if (color[i]) continue;
            dfs(g, i, c++);
        }
        segtree.resize(euler.size()*4);
        build(1, 0, euler.size()-1);
    }

    void dfs(const vector<vector<int>> &g, int u, int c, int h=0) {
        color[u] = c;
        height[u] = h;
        first[u] = euler.size();
        euler.push_back(u);
        vhpos[u] = vh[h].size();
        vh[h].push_back(u);
        for (int v: g[u]) {
            if (color[v]) continue;
            dfs(g, v, c, h+1);
            euler.push_back(u);
        }
    }
    
    // segtree min in euler
    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
            return;
        }
        int mid = (b+e)/2;
        build(node*2, b, mid);
        build(node*2+1, mid+1, e);
        const int l = segtree[node*2], r = segtree[node*2+1];
        segtree[node] = (height[l] < height[r]) ? l : r;
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L) return -1;
        if (b >= L && e <= R) return segtree[node];
        int mid = (b+e)/2;
        int left = query(node*2, b, mid, L, R);
        int right = query(node*2+1, mid+1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        if (color[u] != color[v]) return -1;
        int left = first[u], right = first[v];
        if (left > right) swap(left, right);
        return query(1, 0, euler.size()-1, left, right);
    }

    int pCousins(int v, int p) {
        const int &h = height[v];
        if (p > h) return 0;
        int lo = -1, hi = vhpos[v];
        while (lo+1<hi) {
            int mid = lo+(hi-lo)/2;
            int l = lca(vh[h][mid], v);
            if (l != -1 && height[l] >= h-p) hi = mid;
            else lo = mid;
        }
        const int first = hi;
        lo = vhpos[v], hi = vh[h].size();
        while (lo+1<hi) {
            int mid = lo+(hi-lo)/2;
            int l = lca(vh[h][mid], v);
            if (l != -1 && height[l] >= h-p) lo = mid;
            else hi = mid;
        }
        const int last = lo;
        return last-first;
    }
};

vector<vector<int>> g;

int main() {
    int n; scanf("%d", &n);
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int r; scanf("%d", &r);
        if (r == 0) continue;
        g[r-1].push_back(i);
        g[i].push_back(r-1);
    }
    LCA l(g, n);
    int m; scanf("%d", &m);
    while (m--) {
        int v, p; scanf("%d %d", &v, &p);
        printf("%d ", l.pCousins(v-1, p));
    }
    return 0;
}