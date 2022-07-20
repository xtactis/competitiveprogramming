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
  long long n, p; scanf("%lld%lld", &n, &p);
  long long ans = 1;
  for (long long i = 2; i*i <= p; ++i) {
    long long cnt = 0;
    for (long long j = i; p%j == 0 && j <= p; j *= i) {
      ++cnt;
    }
    if (cnt < n) continue;
    ans = i;
  }
  if (n == 1) ans = p;
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
