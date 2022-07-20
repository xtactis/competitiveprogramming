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

inline long double dist(long long x1, long long y1, long long x2, long long y2) {
  return sqrt((long double)sqr(x1-x2)+sqr(y1-y2));
}

void solve() {
  long long r, x1, y1, x2, y2; scanf("%lld%lld%lld%lld%lld", &r, &x1, &y1, &x2, &y2);
  if (sqr(x1-x2)+sqr(y1-y2) >= r*r) {
    printf("%lld %lld %lld", x1, y1, r);
    return;
  }
  if (x1 == x2 && y1 == y2) {
    printf("%.6Lf %.6Lf %.6Lf", x1+(long double)r/2, (long double)y1, (long double)r/2);
    return;
  }
  long double rr = (r+dist(x1, y1, x2, y2))/2;
  if (x1 == x2) {
    printf("%.6Lf %.6Lf %.6Lf", (long double)x1, y2-rr, rr);
    return;
  }
  if (y1 == y2) {
    printf("%.6Lf %.6Lf %.6Lf", x2-rr, (long double)y1, rr);
    return;
  }
  long double m = (long double)(y2-y1)/(x2-x1);
  debug(rr);
  long double z = r/sqrtl(m*m+1);
  long double xa = x1+z, xb = x1-z;
  long double ya = m*(xa-x1)+y1, yb = m*(xb-x1)+y1;
  debug(xa);  debug(ya);
  debug(xb);  debug(yb);
  debug(dist(x1, y1, xa, ya));
  debug(dist(x1, y1, xb, yb));
  if (dist(x2, y2, xa, ya) > dist(x2, y2, xb, yb)) {
    printf("%.6Lf %.6Lf %.6Lf", (x2+xa)/2, (y2+ya)/2, rr);
  } else {
    printf("%.6Lf %.6Lf %.6Lf", (x2+xb)/2, (y2+yb)/2, rr);
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
