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

long long a[53];

void solve() {
  long long k; scanf("%lld", &k);
  int n = 50;
  puts("50");
  for (int i = 0; i < n; ++i) {
    a[i] = (k+n-1)/n+i;
  }
  if (k%n) {
    k = n-(k%n);
    for (int i = 0; i < k; ++i) {
      int x = max_element(a, a+n)-a;
      a[x] -= n;
      for (int j = 0; j < n; ++j) {
	if (j == x) continue;
	++a[j];
      }
    }
  }
  for (int i = 0; i < n; ++i) printf("%lld ", a[i]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
