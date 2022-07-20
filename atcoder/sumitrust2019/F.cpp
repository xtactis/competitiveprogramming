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

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

void solve() {
  long long t[2], a[2], b[2];
  scanf("%lld%lld%lld%lld%lld%lld", t, t+1, a, a+1, b, b+1);
  long long p[6][2], d[6];
  for (int i = 0; i < 6; ++i) {
    p[i][0] = t[i%2]*a[i%2];
    p[i][1] = t[i%2]*b[i%2];
    if (!i) continue;
    p[i][0] += p[i-1][0];
    p[i][1] += p[i-1][1];
  }
  for (int i = 0; i < 6; ++i) {
    d[i] = p[i][0]-p[i][1];
  }
  if (d[1] == 0 || d[1] == d[3]) {
    puts("infinity");
    return;
  }
  if (sgn(d[0]) == sgn(d[1])) {
    puts("0");
    return;
  }
  if (d[0]%d[1]==0) {
    printf("%lld", abs(d[0]/d[1]*2));
  } else {
    printf("%lld", abs(d[0]/d[1]*2)+1);
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
