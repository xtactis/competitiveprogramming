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
pair<int, int> a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int x, i = 0; i < n; ++i) {
    scanf("%d", &x);
    a[i] = {x, i};
  }
  sort(a, a+n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].second%2 != i%2) ++ans;
  }
  printf("%d", ans/2);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
