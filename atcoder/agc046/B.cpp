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
const int N = 3e3+23;

int a, b, c, d;
long long dp[N][N];

long long rek(int i, int j) {
  if (i < a || j < b) return 0;
  if (i == a && j == b) return 1;
  long long &ret = dp[i][j];
  if (ret != -1) return ret;
  ret = rek(i-1, j)*j%mod;
  ret = (ret + rek(i, j-1)*i%mod)%mod;
  ret = (ret - rek(i-1, j-1)*(i-1)*(j-1)%mod + mod) % mod;
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("%lld", rek(c, d));
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
