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
  int neg = 0, zeros = 0;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (a[i] < 0) ++neg;
    if (a[i] == 0) ++zeros;
    sum += abs(a[i]);
  }
  int m = 2e9;
  if (zeros) --neg;
  if (neg % 2) {
    for (int i = 0; i < n; ++i) {
      m = min(m, abs(a[i]));
    }
  }
  if (m == 2e9) m = 0;
  printf("%lld", sum-2*m);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
