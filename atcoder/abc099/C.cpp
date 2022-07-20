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

vector<int> pows;
int dp[N];
int n;

int dfs(int m = 0) {
  int ret = 1e9;
  if (m > n) return ret;
  if (m == n) return 0;
  if (dp[m]) return dp[m];
  for (int x: pows) {
    if (m+x > n) continue;
    ret = min(ret, 1+dfs(m+x));
  }
  return dp[m] = ret;
}

void solve() {
  scanf("%d", &n);
  pows.push_back(1);
  for (int p = 6; p <= N; p *= 6) {
    pows.push_back(p);
  }
  for (int p = 9; p <= N; p *= 9) {
    pows.push_back(p);
  }
  sort(pows.begin(), pows.end(), greater<int>());
  printf("%d", dfs());
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
