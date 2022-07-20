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

const int N = 5e4+23;
int a[N];

void solve() {
  int n; scanf("%d", &n);
  bool f = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (i && a[i] >= a[i-1]) f = false;
  }
  if (f) puts("NO");
  else puts("YES");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
