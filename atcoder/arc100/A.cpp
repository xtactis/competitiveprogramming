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

const int N = 2e5+34;

long long a[N];
long long b[N];

void solve() {
  int n; scanf("%d", &n);
  long long tot = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    a[i] -= (i+1);
  }
  sort(a, a+n);
  b[0] = a[0];
  for (int i = 1; i < n; ++i) b[i] += b[i-1]+a[i];
  long long ans = 1e15;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, a[i]*(2*i+2-n)-2*b[i]+b[n-1]);
  }
  printf("%lld", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
