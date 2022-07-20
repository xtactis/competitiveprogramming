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

vector<int> ks, khs;

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  long long ans = 0;
  for (int i = k; i <= n; i += k) ++ans;
  ans *= ans*ans;
  if (k % 2 == 0) {
    long long extra = 0;
    for (int i = k-(k/2); i <= n; i += k) ++extra;
    extra *= extra*extra;
    ans += extra;
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
