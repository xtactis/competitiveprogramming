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

const int N = 3e5+23;
const int sqN = 550;

int a[N], h[N];
int d[sqN];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int L = max(a[i]-k, 0), R = min(a[i]+k, N);
    int l = (L+sqN-1)/sqN, r = R/sqN;
    int cur = 0;
    if (l < r-1) {
      for (int j = l; j < r; ++j) cur = max(cur, d[j]);
      for (int j = L; j < l*sqN; ++j) cur = max(cur, h[j]);
      for (int j = R; j >= r*sqN; --j) cur = max(cur, h[j]);
    } else {
      for (int j = L; j <= R; ++j) cur = max(cur, h[j]);
    }
    h[a[i]] = 1+cur;
    d[a[i]/sqN] = max(d[i]/sqN, h[a[i]]);
    ans = max(ans, h[a[i]]);
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
