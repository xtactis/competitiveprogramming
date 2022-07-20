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

int h[10][10];

void solve() {
  int n; scanf("%d", &n);
  long long ans = 0;
  for (int i = 1, p = 1; i <= n; ++i) {
    if (i >= p*10) p *= 10;
    int l = i%10, f = i/p%10;
    
    ++h[f][l];
  }
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      ans += (long long)h[i][j] * h[j][i];
    }
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
