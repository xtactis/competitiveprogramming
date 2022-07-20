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
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
  }
  sort(a, a+n);
  long long lo = 0, hi = n-1;
  vector<pair<long long, long long>> vp;
  while (lo+1 < hi) {
    if (abs(a[hi-1]-(a[lo]-a[hi])) >= abs(a[lo+1]-(a[hi]-a[lo]))) {
      vp.emplace_back(a[lo], a[hi]);
      a[lo] = a[lo]-a[hi--];
    } else {
      vp.emplace_back(a[hi], a[lo]);
      a[hi] = a[hi]-a[lo++];
    }
  }
  printf("%lld\n", a[hi]-a[lo]);
  for (const auto &p: vp) {
    printf("%lld %lld\n", p.first, p.second);
  }
  printf("%lld %lld", a[hi], a[lo]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
