#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

const int mod = 1e9+7;

int n, m;
map<pair<int, int>, int> dp;
vector<long long> a;

int rek(int i, int m) {
  if (m == 1) return 1;
  if (i == n) return 0;
  if (dp.count({i, m})) return dp[{i, m}];
  int lim = upper_bound(a.begin(), a.end(), m)-a.begin();
  long long ret = 0;
  for (int j = 0; j < lim; ++j) {
    if (m%a[j]) continue;
    ret = (ret + rek(i+1, m/a[j])) % mod;
  }
  return dp[{i, m}] = ret;
}

void solve() {
  scanf("%d%d", &n, &m);
  for (long long i = 1; i*i <= m; ++i) {
    if (m%i) continue;
    a.push_back(i);
    if (i*i == m) break;
    a.push_back(m/i);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)a.size(); ++j) {

    }
  }
  printf("%d", rek(0, m));
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
