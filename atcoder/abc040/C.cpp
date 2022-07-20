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

const int N = 1e5+23;
const int inf = 2e9;

int a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int dp[3] = {0, inf, inf};
  for (int i = 0; i < n-1; ++i) {
    dp[1] = min(dp[1], dp[0]+abs(a[i+1]-a[i]));
    if (i+2 < n)
      dp[2] = min(dp[2], dp[0]+abs(a[i+2]-a[i]));
    dp[0] = dp[1];
    dp[1] = dp[2];
    dp[2] = inf;
  }
  printf("%d", dp[0]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
