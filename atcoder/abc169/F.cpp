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

const int N = 3e3+23;
const int mod = 998244353;

long long dp[N][N];
int a[N];

void solve() {
  int n, s; scanf("%d%d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  dp[0][0] = 1;
  for (int i = 0; i <= s; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j+1] = (dp[i][j+1] + dp[i][j]*2) %mod;
      if (i+a[j] <= s)
	dp[i+a[j]][j+1] = (dp[i+a[j]][j+1] + dp[i][j]) % mod;
    }
  }
  printf("%lld", dp[s][n]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
