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

int n;

int dfs(long long x, int t = 0, int f = 0, int s = 0) {
  if (x > n) return 0;
  return (t && f && s)
       + dfs(x*10+3, t+1, f, s)
       + dfs(x*10+5, t, f+1, s)
       + dfs(x*10+7, t, f, s+1);
}

void solve() {
  scanf("%d", &n);
  printf("%d", dfs(0));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
