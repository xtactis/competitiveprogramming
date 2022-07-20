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

int a[N], n;

bool check(int s) {
  long long size = a[s];
  for (int i = 0; i < n; ++i) {
    if (i == s) continue;
    if (a[i] > 2*size) return false;
    size += a[i];
  }
  return true;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int lo = -1, hi = n;
  while (lo+1 < hi) {
    int mid = (lo+hi)/2;
    if (check(mid)) hi = mid;
    else lo = mid;
  }
  printf("%d", n-hi);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
