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

int parent[N], Size[N];

int findParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = findParent(parent[x]);
}

void unionize(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if (a != b) {
    if (Size[a] < Size[b]) swap(a, b);
    parent[a] = b;
    Size[b] += Size[a];
  }
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
    Size[i] = 1;
  }
  for (int x, y, z, i = 0; i < m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    unionize(--x, --y);
  }
  set<int> s;
  for (int i = 0; i < n; ++i) s.insert(findParent(i));
  printf("%d", s.size());
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
