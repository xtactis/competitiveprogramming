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

const int N = 2e5+23;

int a[N], b[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      int l = max(0, j-a[j]),
          r = min(n-1, j+a[j]);
      ++b[l];
      if (r+1 < n) --b[r+1];
    }
    a[0] = b[0];
    bool allsame = true;
    for (int j = 1; j < n; ++j) {
      a[j] = (b[j] += b[j-1]);
      b[j-1] = 0;
      if (a[j] != a[j-1] || a[j] != n) allsame = false;
    }
    if (allsame) break;
    b[n-1] = 0;
  }
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
