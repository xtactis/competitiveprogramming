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
const double eps = 1e-6;

int a[N], n, l;

bool check(double t) {
  double s = 1, t1 = 0, c1 = 0, c2 = 0;
  for (int i = 1; i < n; ++i) {
    if ((a[i]-a[i-1])/s+t1 <= t) {
      t1 += (a[i]-a[i-1])/s;
      c1 = a[i];
      ++s;
    } else {
      c1 += s*(t-t1);
      break;
    }
  }
  s = 1, t1 = 0;
  for (int i = n-2; i >= 0; --i) {
    if ((a[i+1]-a[i])/s+t1 <= t) {
      t1 += (a[i+1]-a[i])/s;
      c2 = l-a[i];
      ++s;
    } else {
      c2 += s*(t-t1);
      break;
    }
  }
  return c1+c2 >= l;
}

void solve() {
  scanf("%d%d", &n, &l);
  a[0] = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  n += 2;
  a[n-1] = l;
  double lo = 0, hi = l;
  while (hi-lo > eps) {
    double mid = (hi+lo)/2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%.6lf\n", lo);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
