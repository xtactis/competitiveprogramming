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

int a[N][N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i]+j);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n/2; ++i) {
    for (int j = 0; j < m/2; ++j) {
      vector<int> v = {a[i][j], a[n-i-1][j], a[i][m-j-1], a[n-i-1][m-j-1]};
      vector<int> t = v;
      long long s = 0;
      for (int e: v) {
	s += e;
      }
      t.push_back(s/4);
      t.push_back((s+3)/4);
      long long mi = 1e13;
      for (int k = 0; k < 6; ++k) {
	long long cur = 0;
	for (int l = 0; l < 4; ++l) {
	  cur += abs(t[k]-v[l]);
	}
	mi = min(mi, cur);
      }
      debug(mi);
      ans += mi;
    }
  }
  if (n%2) {
    for (int i = 0; i < m/2; ++i) {
      ans += abs(a[n/2][i]-a[n/2][m-i-1]);
    }
  }
  if (m%2) {
    for (int i = 0; i < n/2; ++i) {
      ans += abs(a[i][m/2]-a[n-i-1][m/2]);
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
