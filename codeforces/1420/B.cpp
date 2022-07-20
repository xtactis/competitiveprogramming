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
int a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    a[i] = 31-__builtin_clz(a[i]);
  }
  long long ans = 0;
  for (int i = 0; i < 31; ++i) {
    int p = 1 << i, cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] == i) ++cnt;
    }
    ans += 1LL*cnt*(cnt-1)/2;
  }
  printf("%lld\n", ans);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
