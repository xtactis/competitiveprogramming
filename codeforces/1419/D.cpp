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

int a[N], b[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  sort(a, a+n);
  int j = 0;
  for (int i = 1; i < n; i += 2) b[i] = a[j++];
  for (int i = 0; i < n; i += 2) b[i] = a[j++];
  int ans = 0;
  for (int i = 1; i < n-1; ++i) {
    if (b[i] < b[i-1] && b[i] < b[i+1]) ++ans;
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) printf("%d ", b[i]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
