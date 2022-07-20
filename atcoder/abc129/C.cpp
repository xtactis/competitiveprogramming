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

long long dp[N];

void solve() {
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i < N; ++i) {
    dp[i] = (dp[i-1]+dp[i-2]) % mod;
  }
  int n, m; scanf("%d%d", &n, &m);
  long long ans = 1;
  int p = 0;
  for (int c, i = 0; i < m; ++i, p = c) {
    scanf("%d", &c);
    if (!p)
      ans = (ans * dp[c-p]) % mod;
    else
      ans = (ans * dp[c-p-1]) % mod;
  }
  if (p)
    ans = (ans * dp[n-p]) % mod;
  else
    ans = (ans * dp[n-p+1]) % mod;
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
