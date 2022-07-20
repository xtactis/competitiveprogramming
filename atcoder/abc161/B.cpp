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

int a[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  float p = 1./(4*m);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    s += a[i];
  }
  sort(a, a+n, greater<int>());
  for (int i = 0; i < m; ++i) {
    if ((float)a[i]/s < p) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
