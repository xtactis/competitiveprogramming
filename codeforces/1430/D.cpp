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

void solve() {
  int n; scanf("%d", &n);
  char p = 0, cnt = 0;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    char c; scanf(" %c", &c);
    if (p == 0) p = c;
    if (p == c) ++cnt;
    else {
      v.push_back(cnt);
      cnt = 1;
    }
    p = c;
  }
  v.push_back(cnt);
  n = v.size();
  printf("%d\n", n);
  int ans = 0, m = -1;
  for (int i = 0; i < n; ++i) {
    if (m < n && (i > m || v[m] == 1)) {
      for (++m; m < n; ++m) if (v[m] > 1) break;
    }
    if (m < n) {
      --v[m];
    } else {
      ++i;
    }
    ++ans;
  }
  printf("%d\n", ans);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
