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
int n, m, v, p;

bool check(int x) {
  if (a[x]+m < a[p-1]) return false;
  int vv = v-(n-x)-(p-1);
  if (vv <= 0) return true;
  long long c = 1LL*m*vv;
  long long s = 0;
  for (int i = p-1; i < x; ++i) {
    s += a[x]+m-a[i];
  }
  return s >= c;
}

void solve() {
  scanf("%d %d %d %d", &n, &m, &v, &p);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
  }
  sort(a, a+n, greater<long long>());
  int lo = p-1, hi = n;
  while (lo+1<hi) {
    int mid = (lo+hi)/2;
    if (check(mid)) lo = mid;
    else hi = mid;
  }
  printf("%d", lo+1);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
