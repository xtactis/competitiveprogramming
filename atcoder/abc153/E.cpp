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

const int N = 1e3+5;
int a[N], b[N];
int dp[N*10];

void solve() {
  int h, n; scanf("%d%d", &h, &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", a+i, b+i);
  for (int i = 1; i <= h; ++i) {
    dp[i] = dp[max(i-a[0], 0)]+b[0];
    for (int j = 1; j < n; ++j) {
      dp[i] = min(dp[i], dp[max(i-a[j], 0)]+b[j]);
    }
  }
  printf("%d", dp[h]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
