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

const int N = 2e5+23;
int inv[N], cnt[N];

void solve() {
  int n; scanf("%d", &n);
  for (int p, i = 0; i < n; ++i) {
    scanf("%d", &p);
    inv[--p] = i;
    cnt[i] = 1;
  }
  int ans = n-1;
  for (int i = n-2; i >= 0; --i) {
    if (inv[i] < inv[i+1]) {
      cnt[i] = 1+cnt[i+1];
      ans = min(n-cnt[i], ans);
    }
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
