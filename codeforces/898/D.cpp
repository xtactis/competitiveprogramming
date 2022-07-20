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

const int N = 1e6+23;

int h[N];

void solve() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    ++h[a];
  }
  int ans = 0, cnt = 0;
  for (int i = 1; i <= m; ++i) {
    if (cnt == k-1 && h[i]) {
      ++ans;
      h[i] = 0;
    }
    if (h[i]) ++cnt;
  }
  for (int i = m+1; i <= 1e6; ++i) {
    cnt -= h[i-m];
    if (cnt == k-1 && h[i]) {
      ++ans;
      h[i] = 0;
    }
    if (h[i]) ++cnt;
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
