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
int a[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int u, v, i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    ++a[u]; --a[v];
  }
  for (int i = 1; i < n; ++i) {
    a[i] += a[i-1];
    if (a[i]%2) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
