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
  int a, b, c, k; scanf("%d%d%d%d", &a, &b, &c, &k);
  for (int i = 0; i < k; ++i) {
    if (b <= a) b *= 2;
    else if (c <= b) c *= 2;
    if (a < b && b < c) break;
  }
  if (a < b && b < c) printf("Yes");
  else printf("No");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
