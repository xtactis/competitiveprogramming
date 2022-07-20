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
const int N = 2e3+23;

int dp[N];

int rek(int n) {
  if (n < 3) return 0;
  if (n < 6) return 1;
  int &ret = dp[n];
  if (ret != -1) return ret;
  ret = 1;
  for (int i = 3; i <= n-3; ++i) {
    ret = (ret+rek(n-i))%mod;
  }
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  int n; scanf("%d", &n);
  printf("%d", rek(n));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
