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

const int N = 3e5+23;
const int inf = 1e9;

int p[N], m[N], a[N];

void solve() {
  int n; scanf("%d", &n);
  memset(p, -1, sizeof(p));
  memset(m, 0, sizeof(m));
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    m[a[i]] = max(m[a[i]], i-p[a[i]]);
    p[a[i]] = i;
  }
  vector<int> h(N, inf);
  for (int i = 1; i <= n; ++i) {
    m[i] = max(m[i], n-p[i]);
    h[m[i]] = min(h[m[i]], i);
  }
  int j = 1, mimi = h[j];
  for (int i = 1; i <= n; ++i) {
    if (mimi == inf) printf("-1 ");
    else printf("%d ", mimi);
    mimi = min(h[++j], mimi);
  }
  puts("");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
