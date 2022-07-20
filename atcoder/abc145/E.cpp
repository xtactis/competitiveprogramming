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

const int T = 3e3+23;
const int N = 3e3+23;

long long dp[N][T];
pair<int, int> a[N];
int n, t;

long long rek(int pos, int w) {
  if (w >= t) return 0;
  if (n == pos) return 0;
  long long &ret = dp[pos][w];
  if (ret != -1) return ret;
  return ret = max(rek(pos+1, w), rek(pos+1, w+a[pos].first)+a[pos].second);
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a, a+n, [](const pair<int, int> &x, const pair<int, int> &y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
  });
  printf("%lld", rek(0, 0));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
