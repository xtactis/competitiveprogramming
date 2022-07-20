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

long long a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", a+i);
  if (n == 1) {
    printf("1 1\n%lld\n1 1\n0\n1 1\n0", -a[0]);
    return;
  }
  printf("1 %d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%lld ", -a[i]%(n-1)*n);
    a[i] -= a[i]%(n-1)*n;
  }
  printf("\n1 %d\n", n-1);
  for (int i = 0; i < n-1; ++i) {
    printf("%lld ", -a[i]);
    a[i] = 0;
  }
  printf("\n2 %d\n", n);
  for (int i = 1; i < n; ++i) {
    printf("%lld ", -a[i]);
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
