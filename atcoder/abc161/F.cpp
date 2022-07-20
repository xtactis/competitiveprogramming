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
  if (n == 2) {
    printf("1");
    return;
  }
  int ans = 2; // n and n-1
  for (long long i = 2; i*i <= n; ++i) {
    if ((n-1) % i == 0) {
      ++ans;
      if ((n-1) / i != i) ++ans;
    }
    if (n % i) continue;
    long long x = n;
    while (x % i == 0) {
      x /= i;
    }
    ans += x % i == 1;
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
