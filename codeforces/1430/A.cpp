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
  for (int i = 0; i <= n; i += 3) {
    for (int j = 0; j <= n; j += 5) {
      if ((n-i-j)%7) continue;
      printf("%d %d %d\n", i/3, j/5, (n-j-i)/7);
      return;
    }
  }
  puts("-1");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
