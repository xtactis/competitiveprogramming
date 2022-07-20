#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

const int N = 1e5+23;

vector<int> a[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int l, v, i = 0; i < n; ++i) {
    scanf("%d%d", &l, &v);
    a[l].emplace_back(v);
  }
  int ans = 0;
  map<int, int> s;
  for (int i = 1; i <= m; ++i) {
    if (s.size() == 0 && a[i].size() == 0) continue;
    for (int e: a[i]) {
      ++s[e];
    }
    const int x = s.rbegin()->first;
    ans += x;
    if (--s[x] == 0) s.erase(x);
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
