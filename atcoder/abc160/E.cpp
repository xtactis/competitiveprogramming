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

long long r[N], g[N];
priority_queue<long long> pq;

void solve() {
  int x, y, a, b, c; scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
  for (int i = 0; i < a; ++i) scanf("%lld", r+i);
  for (int i = 0; i < b; ++i) scanf("%lld", g+i);
  for (int t, i = 0; i < c; ++i) {
    scanf("%lld", &t);
    pq.push(t);
  }
  sort(r, r+a, greater<long long>());
  sort(g, g+b, greater<long long>());
  long long ans = 0;
  for (int i = 0; i < x; ++i) {
    ans += r[i];
    if (pq.empty() || pq.top() <= r[i]) continue;
    ans = ans-r[i]+pq.top();
    pq.pop();
    pq.push(r[i]);
  }
  for (int i = 0; i < y; ++i) {
    ans += g[i];
    if (pq.empty() || pq.top() <= g[i]) continue;
    ans = ans-g[i]+pq.top();
    pq.pop();
    pq.push(g[i]);
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
