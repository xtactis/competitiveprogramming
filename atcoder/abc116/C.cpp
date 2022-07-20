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
int a[N], b[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    b[i] = a[i];
  }
  sort(b, b+n);
  for (int i = n-1; i > 0; --i) {
    b[i] -= b[i-1];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!b[i]) continue;
    bool f = true;
    for (int j = 0; j < n; ++j) {
      if (a[j]) {
	a[j] -= b[i];
	f = false;
      } else {
	if (!f)	ans += b[i];
	f = true;
      }
    }
    if (!f) ans += b[i];
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
