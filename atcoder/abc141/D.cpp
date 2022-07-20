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

const int N = 1e5+34;

priority_queue<int> pq;

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int a; scanf("%d", &a);
    pq.push(a);
    ans += a;
  }
  for (int i = 0; i < m; ++i) {
    int value = pq.top(); pq.pop();
    ans -= value;
    ans += value/2;
    pq.push(value/2);
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
