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

void solve() {
  long long n; scanf("%lld", &n);
  long long ans = 0;
  for (long long i = 1; i*i <= n; ++i) {
    if (n%i) continue;
    if (i>1 && n%(i-1) == n/(i-1)) ans += i-1;
    if (n/i>1 && n%(n/i-1) == n/(n/i-1)) ans += n/i-1;
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
