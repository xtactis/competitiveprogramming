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
int n, k;

bool check(int x) {
  int cnt = k;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= x) continue;
    cnt -= a[i]/x;
    if (cnt < 0) return false;
  }
  return true;
}

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int lo = 0, hi = 1e9+1;
  while (lo+1 < hi) {
    int mid = (lo+hi)/2;
    if (check(mid)) hi = mid;
    else lo = mid;
  }
  printf("%d", hi);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
