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

int a[N], c[N], g[N], t[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char x; scanf(" %c", &x);
    if (i) { a[i] = a[i-1]; c[i] = c[i-1]; g[i] = g[i-1]; t[i] = t[i-1];}
    if (x == 'A') {
      ++a[i];
    } else if (x == 'T') {
      ++t[i];
    } else if (x == 'C') {
      ++c[i];
    } else {
      ++g[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      int x = a[j]-t[j], y = c[j]-g[j];
      if (i) {x -= a[i-1]-t[i-1]; y -= c[i-1]-g[i-1];}
      if (!x && !y) {
	debug(i);
	debug(j);
	++ans;
      }
    }
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
