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

const int mod = 1e9+7;
const int N = 1e5+23;

int c[3];

void solve() {
  int n; scanf("%d", &n);
  long long ans = 1;
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    int cnt = 0, sel = 0;
    for (int j = 0; j < 3; ++j) {
      if (c[j] == a) {
	++cnt;
	sel = j;
      }
    }
    (ans *= cnt) %= mod;
    ++c[sel];
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
