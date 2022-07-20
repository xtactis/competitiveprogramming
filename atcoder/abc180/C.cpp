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

void solve() {
  long long n; scanf("%lld", &n);
  set<long long> s;
  for (long long i = 1; i*i <= n; ++i) {
    if (n%i) continue;
    s.insert(i);
    if (n/i == i) break;
    s.insert(n/i);
  }
  for (long long e: s) printf("%lld\n", e);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
