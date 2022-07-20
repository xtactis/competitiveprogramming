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
  int n; scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    printf("%d ", i);
  }
  int s = n*(n+1)/2-1;
  int i = n+1;
  if (i%2 != s%2) ++i;
  for (; i <= 30000; i+=2) {
    bool f = false;
    for (int j = 3; j <= n; ++j) {
      if (__gcd(j, s-j+i) == 1) {
	f = true;
	break;
      }
    }
    if (f) continue;
    if (__gcd(i, s) == 1) continue;
    printf("%d", i);
    return;
  }
  assert(false);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
