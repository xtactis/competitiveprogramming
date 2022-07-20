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

const int N = 1e7+23;

long long f[N];

void solve() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j+=i) {
      ++f[j];
    }
  }
  int n; scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += i*f[i];
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
