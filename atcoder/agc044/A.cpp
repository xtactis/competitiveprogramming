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

long long n, a, b, c, d;
map<long long, long long> dp;

long long rek(long long x) {
  if (x == 0) return 0;
  if (dp.find(x) != dp.end()) return dp[x];
  dp[x] = LLONG_MAX;
  if (x < LLONG_MAX/d) dp[x] = x*d;
  return dp[x] = min({dp[x], d*(x-x/2*2)+a+rek(x/2), d*(x-x/3*3)+b+rek(x/3), d*(x-x/5*5)+c+rek(x/5),
		      d*((x+1)/2*2-x)+a+rek((x+1)/2), d*((x+2)/3*3-x)+b+rek((x+2)/3), d*((x+4)/5*5-x)+c+rek((x+4)/5)});
}

void solve() {
  dp.clear();
  scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
  printf("%lld\n", rek(n));
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
