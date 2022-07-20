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

long long a[N], n, h[N];
vector<int> v;
long long dp[N][2];

long long rek(int i, int prev) {
  if (i >= (int)v.size()) return 0;
  bool ok = prev-1 != v[i];
  if (dp[i][ok] != -1) return dp[i][ok];
  if (!ok) return dp[i][ok] = rek(i+1, prev);
  return dp[i][ok] = max(rek(i+1, prev), h[v[i]]*v[i]+rek(i+1, v[i]));
}

void solve() {
  for (int i = 0; i < N; ++i) dp[i][0] = dp[i][1] = -1;
  scanf("%lld", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    ++h[a[i]];
  }
  sort(a, a+n, greater<int>());
  for (int i = 0; i < n; ++i) if (v.empty() || v.back() != a[i]) v.push_back(a[i]);
  printf("%lld\n", rek(0, -500));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
