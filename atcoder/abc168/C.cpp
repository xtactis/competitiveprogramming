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

const double EPSILON = 1e-9;
const double PI = acos(-1);

bool eq(double a, double b) {
  return abs(a-b) <= EPSILON;
}

void solve() {
  int a, b, h, m; scanf("%d%d%d%d", &a, &b, &h, &m);
  h = h*60+m;
  double H = 1.*h/(12*60), M = 1.*m/60;
  if (eq(H, M)) {
    printf("%d", abs(a-b));
    return;
  }
  double angle;
  if (M < H) {
    angle = (H - M)*2*PI;
  } else {
    angle = (M - H)*2*PI;
  }
  double ans = sqrt(a*a+b*b - 2*a*b*cos(angle));
  printf("%.9f", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
