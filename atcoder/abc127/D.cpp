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

const int N = 1e5;

int a[N];
vector<pair<int, int>> p;

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  for (int i = 0; i < m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    p.emplace_back(y, x);
  }
  sort(p.begin(), p.end(), greater<pair<int, int>>());
  long long ans = 0;
  int z = 0;
  for (int i = 0; i < (int)p.size() && z < n; ++i) {
    while (z < n && p[i].second && p[i].first > a[z]) {
      z++;
      ans += p[i].first;
      --p[i].second;
    }
  }
  for (; z < n; ++z) ans += a[z];
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
