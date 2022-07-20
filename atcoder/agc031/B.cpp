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

const int N = 2e5+23;
const int mod = 1e9+7;

vector<int> c[N];
int n, a[N], dp[N];

int rek(int pos) {
  if (pos == n) return 1;
  int &ret = dp[pos];
  if (ret != -1) return ret;
  ret = rek(pos+1);
  if (pos+1 < n && a[pos+1] == a[pos]) return ret;
  int A = upper_bound(c[a[pos]].begin(), c[a[pos]].end(), pos)-c[a[pos]].begin();
  if (A < c[a[pos]].size()) {
    ret = (ret + rek(c[a[pos]][A])) % mod;
  }
  return ret;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (c[a[i]].size() && c[a[i]].back() == i-1) c[a[i]].pop_back();
    c[a[i]].push_back(i);
  }
  dp[n] = 1;
  for (int i = n-1; i >= 0; --i) {
    (dp[i] += dp[i+1]) %= mod;
    if (c[a[i]].empty()) continue;
    if (i+1 < n && a[i+1] == a[i]) continue;;
    int A = c[a[i]].back();
    if (A == i) continue;
    c[a[i]].pop_back();
    (dp[i] += dp[A]) %= mod;
  }
  printf("%d", dp[0]);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
