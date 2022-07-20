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

const int N = 5e3+23;
const long long inf = N*2e9;

int p[N], c[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", p+i), --p[i];
  for (int i = 0; i < n; ++i) scanf("%d", c+i);
  long long ans = -inf;
  for (int i = 0; i < n; ++i) {
    int len = 1;
    long long e = c[i];
    for (int j = p[i]; j != i; j = p[j]) {
      e += c[j];
      ++len;
    }
    long long cur = 0;
    for (int j = i, cnt = 0; cnt < min(k+1, len); j = p[j], ++cnt) {
      cur += c[j];
      if (e > 0) {
	if (cnt < k%len)
	  ans = max(ans, k/len*e+cur);
	else
	  ans = max(ans, (k/len-1)*e+cur);
      } else {
	ans = max(ans, cur);
      }
    }
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
