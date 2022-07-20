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

long long a[N], b[N], c[N];

void solve() {
  int x, y, z, K; scanf("%d%d%d%d", &x, &y, &z, &K);
  for (int i = 0; i < x; ++i) scanf("%lld", a+i);
  for (int i = 0; i < y; ++i) scanf("%lld", b+i);
  for (int i = 0; i < z; ++i) scanf("%lld", c+i);
  sort(a, a+x, greater<long long>());
  sort(b, b+y, greater<long long>());
  sort(c, c+z, greater<long long>());
  vector<long long> v;
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      for (int k = 0; k < z; ++k) {
	if ((i+1)*(j+1)*(k+1) > K) break;
	v.push_back(a[i]+b[j]+c[k]);
      }
    }
  }
  sort(v.begin(), v.end(), greater<long long>());
  for (int i = 0; i < K; ++i) printf("%lld\n", v[i]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
