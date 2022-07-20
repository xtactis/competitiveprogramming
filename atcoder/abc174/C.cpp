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
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += 7;
    cur %= n;
    if (cur == 0) {
      printf("%d", i+1);
      return;
    }
    cur *= 10;
  }
  printf("-1");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
