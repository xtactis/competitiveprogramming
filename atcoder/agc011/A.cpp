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
  int n, c, k; scanf("%d%d%d", &n, &c, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int ans = 0, ppl = 0, pb = -1;
  for (int i = 0; i < n; ++i) {
    if (!ppl || a[i]-k > pb) {
      ++ans;
      ppl = c;
      pb = a[i];
    }
    --ppl;
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
