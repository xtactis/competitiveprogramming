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

const int N = 123;

double dp[N][N][N];

double dfs(int a, int b, int c) {
  if (a == 100 || b == 100 || c == 100) return 0;
  double &ret = dp[a][b][c];
  if (ret != 0) return ret;
  return ret = (1+dfs(a+1, b, c)) * (1.*a/(a+b+c)) + 
               (1+dfs(a, b+1, c)) * (1.*b/(a+b+c)) +
               (1+dfs(a, b, c+1)) * (1.*c/(a+b+c));
}

void solve() {
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  printf("%.8lf", dfs(a, b, c));
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
