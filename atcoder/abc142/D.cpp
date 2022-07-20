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

bool prime(long long n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (long long i = 3; i*i <= n; i += 2) {
    if (n % i) continue;
    return false;
  }
  return true;
}

void solve() {
  long long a, b; scanf("%lld%lld", &a, &b);
  long long g = __gcd(a, b);
  int ans = 1;
  for (long long i = 1; i*i <= g; ++i) {
    if (g % i) continue;
    if (prime(i)) ++ans;
    if (prime(g/i)) ++ans;
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
