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

const int N = 2e5+23;
const int K = 12;
const int mod = 998244353;

int l[K], r[K];
long long cum[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", l+i, r+i);
  }
  long long ans;
  cum[1] = 1;
  for (int i = 2; i <= n; ++i) {
    ans = 0;
    for (int j = 0; j < k; ++j) {
      ans = (ans + cum[max(0, i-l[j])] - cum[max(0, (i-r[j])-1)]) % mod;
    }
    cum[i] = (cum[i-1] + ans) % mod;
  }
  printf("%lld", (ans+mod)%mod);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
