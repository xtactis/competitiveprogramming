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

inline long long sqr(long long x) {
  return x*x;
}

void solve() {
  long long a[3]; scanf("%lld%lld%lld", a, a+1, a+2);
  if (a[0] == a[1] && a[1] == a[2]) printf("%lld\n", a[0]);
  else {
    sort(a, a+3);
    printf("%.0f\n", ceil(sqrt(sqr(a[2]-a[0])+a[1]*a[1])));
  }
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
