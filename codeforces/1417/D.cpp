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

const int N = 1e4+23;

int a[N];

void solve() {
  int n; scanf("%d", &n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    s += a[i];
  }
  if (s%n) {
    puts("-1");
    return;
  }
  s /= n;
  vector<array<int, 3>> ans;
  for (int i = 1; i < n; ++i) {
    int r = (i+1-a[i]%(i+1))%(i+1);
    ans.push_back({1, i+1, r});
    a[0] -= r;
    a[i] += r;
    r = a[i]/(i+1);
    ans.push_back({i+1, 1, r});
    r *= (i+1);
    a[i] -= r;
    a[0] += r;
  }
  for (int i = 1; i < n; ++i) {
    ans.push_back({1, i+1, s-a[i]});
  }
  printf("%d\n", ans.size());
  for (const auto &e: ans) {
    printf("%d %d %d\n", e[0], e[1], e[2]);
  }
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
