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
  int ans = 0;
  for (long long i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    for (long long j = i; n%j==0; j *= i) {
      ++ans;
      n /= j;
    }
    while (n%i == 0) n /= i;
  }
  if (n > 1) ++ans;
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
