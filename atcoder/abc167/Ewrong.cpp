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

const int mod = 998244353;
const int N = 2e5+23;

int n, m, k;
long long dp[N];

void solve() {
  scanf("%d%d%d", &n, &m, &k); ++k;
  long long cur = 1;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = cur;
    if (i == n) {
      dp[i] = dp[i] * m % mod;
    } else {
      dp[i] = dp[i] * (m-1) % mod;
    }
    cur = (cur + dp[i]) % mod;
    if (i-k >= 0) cur = (cur - dp[i-k] + mod) % mod;
  }
  printf("%lld", dp[n]);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
