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

const int mod = 1e9+7;
const int N = 2e3+23;

int a[N];

void solve() {
  long long n, k; scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (a[j] >= a[i]) continue;
      if (j > i) {
	ans = (ans + k*(k+1)/2) % mod;
      } else {
	ans = (ans + (k-1)*k/2) % mod;
      }
    }
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
