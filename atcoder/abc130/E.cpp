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

const int N = 2e3+23;
const int S = 1e5+23;
const int mod = 1e9+7;

int n, m;
int a[N], b[N];
long long dp[N][N], sum[N][N];

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int j = 1; j <= m; ++j) scanf("%d", b+j);
  sum[0][0] = dp[0][0] = 1;
  for (int i = 0; i <= n; ++i) sum[i][0] = 1;
  for (int i = 0; i <= m; ++i) sum[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) dp[i][j] = (sum[i-1][j-1] + 1) % mod;
      sum[i][j] = (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j] + mod) % mod;
    }
  }
  printf("%lld", (sum[n][m]+1)*500000004%mod);
}

int main() {
  //  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
