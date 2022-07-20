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

void solve() {
  long long n, k; scanf("%lld%lld", &n, &k);
  long long ans = 0;
  for (long long i = k; i <= n+1; ++i) {
    long long min_ = i*(i-1)/2;
    long long max_ = n*(n+1)/2 - (n-i)*(n-i+1)/2;
    ans = (ans + (max_ - min_ + 1)) % mod;
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
