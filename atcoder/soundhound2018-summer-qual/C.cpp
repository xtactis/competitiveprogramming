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
  int n, m, d; scanf("%d%d%d", &n, &m, &d);
  if (d == 0) {
    printf("%.6f", 1.*(m-1)/n);
  } else {
    printf("%.6f", 1.*(m-1)/(1.*n*n/(2*(n-d))));
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
