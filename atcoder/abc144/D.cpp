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

const double eps = 1e-6;
const double pi = acos(-1);

int a, b, x;

bool check(double alfa) {
  if (alfa > atan(1.*a/b)) {
    
  } else {

  }
}

void solve() {
  scanf("%d%d%d", &a, &b, &x);
  double lo = 0, hi = pi;
  while (hi-lo > eps) {
    double mid = (hi+lo)/2;
    if (check(mid)) hi = mid;
    else lo = mid;
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
