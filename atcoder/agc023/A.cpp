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

const int N = 2e5+23;

long long a[N];
map<long long, long long> h;

void solve() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a+i);
    a[i] += a[i-1];
    ++h[a[i]];
  }
  ++h[0];
  long long ans = 0;
  for (const auto &e: h) {
    if (e.second < 2) continue;
    ans += (e.second-1)*(e.second)/2;
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
