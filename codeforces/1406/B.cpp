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

int a[N];

void solve() {
  int n; scanf("%d", &n);
  int poss = 0, negs = 0, zeros = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (a[i] > 0) ++poss;
    else if (a[i] < 0) ++negs;
    else ++zeros;
  }
  sort(a, a+n, [](int x, int y){return abs(x) > abs(y);});
  long long ans = 1;
  for (int i = 0; i < 5; ++i) ans *= a[i];
  if (ans < 0) {
    int fn = -1, fp = -1;
    for (int i = 5; i < n; ++i) {
      if (a[i] < 0 && fn == -1) fn = i;
      if (a[i] > 0 && fp == -1) fp = i;
    }
    int neg = -1, pos = -1;
    for (int i = 0; i < 5; ++i) {
      if (a[i] < 0) neg = i;
      if (a[i] > 0) pos = i;
    }
    if (fn != -1 && pos != -1 && fp != -1 && neg != -1) {
      if (ans/a[pos]*a[fn] > ans/a[neg]*a[fp]) {
	ans = ans/a[pos]*a[fn];
      } else {
	ans = ans/a[neg]*a[fp];
      }
    } else if (fn != -1 && pos != -1) {
      ans = ans/a[pos]*a[fn];
    } else if (fp != -1 && neg != -1) {
      ans = ans/a[neg]*a[fp];
    } else if (zeros) {
      ans = 0;
    } else {
      ans = 1;
      for (int i = n-1; i >= n-5; --i) {
	ans *= a[i];
      }
    }
  }
  printf("%lld\n", ans);
}

int main() {
  init();
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
