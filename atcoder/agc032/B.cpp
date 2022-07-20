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
  printf("%d\n", n*(n-1)/2 - n/2);
  for (int i = 1; i < n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      if (n%2 == 0 && j == n-i+1) continue;
      if (n%2 == 1 && j == n-i) continue;
      printf("%d %d\n", i, j);
    }
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
