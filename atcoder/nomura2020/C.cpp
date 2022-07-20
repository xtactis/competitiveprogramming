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

long long a[N], b[N];

void solve() {
  int n; scanf("%d", &n);
  long long capacity = 1;
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    scanf("%lld", a+i);
    if (a[i] > capacity) {
      printf("-1");
      return;
    }
    b[i] = capacity;
    if (capacity > 1e15) continue;
    capacity = (capacity-a[i])*2;
  }
  for (int i = n; i >= 0; --i) {
    a[i] += a[i+1];
    ans += min(b[i], a[i]);
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
