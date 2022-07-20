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
  int n, x; scanf("%d%d", &n, &x);
  if (x == 1 || x == n*2-1) {
    puts("No");
    return;
  }
  puts("Yes");
  if (n == x) {
    for (int i = 1; i <= 2*n-1; ++i)
      printf("%d\n", i);
  } else if (x > n) {
    for (int i = 1; i < n; ++i)
      printf("%d\n", i);
    printf("%d\n%d\n%d\n", x, n*2-1, n);
    for (int i = n+1; i < n*2-1; ++i)
      if (i != x)
	printf("%d\n", i);
  } else if (x < n) {
    for (int i = 2; i < n; ++i)
      if (i != x)
	printf("%d\n", i);
    printf("%d\n1\n%d\n", n, x);
    for (int i = n+1; i <= n*2-1; ++i)
      printf("%d\n", i);
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
