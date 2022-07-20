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
  for (long long i = 3, a = 1; i <= n; i *= 3, ++a) {
    for (long long j = 5, b = 1; j <= n-1; j *= 5, ++b) {
      if (i == n-j) {
	printf("%lld %lld", a, b);
	return;
      }
    }
  }
  printf("-1");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
