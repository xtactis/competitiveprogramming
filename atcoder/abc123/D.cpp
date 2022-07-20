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

const int N = 1e3+23;
long long a[N], b[N], c[N];
vector<long long> d;

void solve() {
  int x, y, z, k; scanf("%d%d%d%d", &x, &y, &z, &k);
  for (int i = 0; i < x; ++i) scanf("%lld", a+i);
  for (int i = 0; i < y; ++i) scanf("%lld", b+i);
  for (int i = 0; i < z; ++i) scanf("%lld", c+i);
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      d.push_back(a[i]+b[j]);
    }
  }
  sort(c, c+z, greater<long long>());
  sort(d.begin(), d.end(), greater<long long>());
  vector<long long> sperma;
  for (int i = 0; i < min(k, (int)d.size()); ++i) {
    for (int j = 0; j < z; ++j) {
      sperma.push_back(d[i]+c[j]);
    }
  }
  sort(sperma.begin(), sperma.end(), greater<long long>());
  for (long long e: sperma) {
    printf("%lld\n", e);
    if (--k <= 0) return;
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
