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
  puts("2");
  if (n == 2) {
    puts("1 2");
    return;
  }
  printf("%d %d\n%d %d\n", n, n-2, n-1, n-1);
  for (int i = n-1; i > 2; --i) {
    printf("%d %d\n", i, i-2);
  }
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
