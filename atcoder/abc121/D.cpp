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

long long count(long long a, long long i) {
  long long p = 1LL<<(i+1),
            x = a/p*(p/2);
  if (a&(1LL<<i)) {
    x += a%(p/2)+1;
  }
  return x;
}

void solve() {
  long long a, b; scanf("%lld%lld", &a, &b);
  long long ans = 0;
  a = max(0LL, a-1);
  for (long long i = 0; i < 63; ++i) {
    ans += ((count(b, i) - count(a, i))%2)<<i;
  }
  printf("%lld", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
