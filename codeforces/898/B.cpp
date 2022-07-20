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
  int n, a, b; scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i <= 10000000; ++i) {
    int cur = a*i;
    if (a*i > n) {
      printf("NO");
      return;
    }
    if ((n-a*i)%b == 0) {
      printf("YES\n%d %d", i, (n-a*i)/b);
      return;
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
