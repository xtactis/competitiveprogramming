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

const int N = 123;
const int mod = 1e9+7;

int n;
long long dp[N][4][4][4];

long long rek(int i, int ppp, int pp, int p) {
  if (i == n) return 1;
  long long &ret = dp[i][ppp][pp][p];
  if (ret != -1) return ret;
  ret = 0;
  ret = (ret + rek(i+1, pp, p, 0)) % mod; // 'A'
  if (!((pp == 0 && p == 2) || (ppp == 0 && p == 2) || (ppp == 0 && pp == 2) || (pp == 2 && p == 0)))
    ret = (ret + rek(i+1, pp, p, 1)) % mod; // 'C'
  if (!(pp == 0 && p == 1))
    ret = (ret + rek(i+1, pp, p, 2)) % mod; // 'G'
  ret = (ret + rek(i+1, pp, p, 3)) % mod; // 'T'
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  printf("%lld", rek(0, 3, 3, 3));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
