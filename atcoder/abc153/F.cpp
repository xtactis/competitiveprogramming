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

vector<pair<int, int>> v;

void solve() {
  int n, d, a; scanf("%d%d%d", &n, &d, &a);
  for (int x, h, i = 0; i < n; ++i) {
    scanf("%d%d", &x, &h);
    v.emplace_back(x, h);
  }
  sort(v.begin(), v.end());
  long long sub = 0, ans = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    while (!q.empty() && q.front().first < v[i].first) {
      sub -= q.front().second;
      q.pop();
    }
    v[i].second -= sub;
    if (v[i].second <= 0) continue;
    long long bomb = (v[i].second+a-1)/a;
    sub += bomb*a;
    ans += bomb;
    q.emplace(v[i].first+d*2, bomb*a);
  }
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
