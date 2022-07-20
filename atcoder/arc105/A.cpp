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

int solve() {
  int a[4]; cin >> a[0] >> a[1] >> a[2] >> a[3];
  for (int i = 0; i < (1 << 4); ++i) {
    int x = 0;
    for (int j = 0; j < 4; ++j) {
      if (i&(1<<j)) x += a[j];
      else x -= a[j];
    }
    if (!x) return !printf("Yes");
  }
  return !printf("No");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
