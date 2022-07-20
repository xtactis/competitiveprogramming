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
  int n, t; scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  map<int, int> m;
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (t-a[i] == a[i]) {
      ++c;
      continue;
    }
    if (!m.count(a[i])) {
      m[a[i]] = 0;
      m[t-a[i]] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (t-a[i] == a[i]) {
      a[i] = c > 0;
      c -= 2;
    } else {
      a[i] = m[a[i]];
    }
    printf("%d ", a[i]);
  }
  puts("");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
