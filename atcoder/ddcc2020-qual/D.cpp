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

const int N = 2e5+23;
int a[N];

int fix(int d) {
  return d/10+d%10;
}

long long simplify(int d, long long c, int &dout) {
  dout = d;
  if (c == 1) return 0;
  long long ret = c/2;
  int origD = d;
  d += d;
  if (d >= 10) {
    ret += c/2;
    d = fix(d);
  }
  ret += simplify(d, c/2, dout);
  if (c%2) {
    dout += origD;
    ++ret;
    if (dout >= 10) {
      dout = fix(dout);
      ++ret;
    }
  }
  return ret;
}

void solve() {
  int n; scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int d; long long c;
    scanf("%d%lld", &d, &c);
    ans += simplify(d, c, d);
    a[i] = d;
  }
  for (int i = 1; i < n; ++i) {
    a[i] += a[i-1];
    ++ans;
    if (a[i] >= 10) {
      a[i] = fix(a[i]);
      ++ans;
    }
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
