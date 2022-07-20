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

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

const int N = 1e5+23;

long long dp[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  
  long long ans = 0;
  for (int i = k; i >= 1; --i) {
    dp[i] = binpow(k/i, n);
    for (int j = i+i; j <= k; j += i) {
      dp[i] = (dp[i] - dp[j] + mod) % mod;
    }
    ans = (ans + dp[i]*i%mod) % mod;
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
