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
int a[N], f[N], ind[N];
long long b[N];
long long n, k;

bool check(long long target) {
  long long kk = k;
  for (int i = 0; i < n; ++i) {
    long long cur = 1LL*a[i]*f[i];
    if (cur <= target) continue;
    int sub = (cur-target+f[i]-1)/f[i];
    if (kk < sub) return false;
    kk -= sub;
  }
  return true;
}

void solve() {
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", f+i);
    ind[i] = i;
  }
  for (int i = n; i < N; ++i) ind[i] = n;
  sort(f, f+n, greater<int>());
  sort(a, a+n);
  long long lo = -1, hi = 1e12+1;
  while (lo+1<hi) {
    long long mid = (lo+hi)/2;
    if (check(mid)) hi = mid;
    else lo = mid;
  }
  printf("%lld", hi);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
