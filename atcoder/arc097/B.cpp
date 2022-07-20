#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 1e5+23;

int a[N], parent[N], SIZE[N];

int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (SIZE[a] < SIZE[b]) swap(a, b);
    parent[b] = a;
    SIZE[a] += SIZE[b];
  }
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int p, i = 0; i < n; ++i) {
    scanf("%d", &p);
    a[p-1] = i;
    parent[i] = i;
    SIZE[i] = 1;
  }
  for (int x, y, i = 0; i < m; ++i) {
    scanf("%d %d", &x, &y);
    --x; --y;
    union_sets(x, y);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (find_set(i) == find_set(a[i])) ++ans;
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
