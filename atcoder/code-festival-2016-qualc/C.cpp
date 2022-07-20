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
const int mod = 1e9+7;

int a[N], t[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t+i);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  if (t[n-1] != a[0]) {
    puts("0");
    return;
  }
  long long ans = 1;
  for (int i = 1; i < n-1; ++i) {
    if (a[i] != a[i+1]) {
      if (a[i] > t[i]) {
	puts("0");
	return;
      }
      continue;
    }
    if (t[i] != t[i-1]) {
      if (t[i] > a[i]) {
	puts("0");
	return;
      }
      continue;
    }
    ans = ans * min(a[i], t[i]) % mod;
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
