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
const int mod = 1e9+7;

int a[N];

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  long long ans = 1;
  if (k == n) {
    for (int i = 0; i < n; ++i) {
      ans = (ans * a[i]) % mod;
    }
    printf("%lld", (ans+mod)%mod);
    return;
  }
  sort(a, a+n);
  if (a[n-1] <= 0 && k%2) {
    for (int i = n-1; i >= 0 && k; --i) {
      ans = (ans * a[i]) % mod;
      --k;
    }
    printf("%lld", (ans+mod)%mod);
    return;
  }
  sort(a, a+n, [](int x, int y){return abs(x) > abs(y);});
  long long neg = -2e9, pos = 2e9;
  for (int i = 0; i < k; ++i) {
    if (a[i] < 0) neg = a[i];
    if (a[i] > 0) pos = a[i];
    ans = (ans * a[i]) % mod;
  }
  if (ans >= 0) {
    printf("%lld", ans);
    return;
  }
  long long neg2 = -2e9, pos2 = 2e9;
  for (int i = k; i < n; ++i) {
    if (a[i] < 0 && neg2 == -2e9) neg2 = a[i];
    if (a[i] > 0 && pos2 == 2e9) pos2 = a[i];
  }
  if (neg != -2e9 && neg2 != -2e9 && pos != 2e9 && pos2 != 2e9) {
    if (neg2*neg > pos*pos2) {
      ans = ans * neg2 % mod * binpow(pos, mod-2) % mod;
    } else {
      ans = ans * pos2 % mod * binpow(neg, mod-2) % mod;
    }
  } else if (neg2 != -2e9 && pos != 2e9) {
    ans = ans * neg2 % mod * binpow(pos, mod-2) % mod;
  } else {
    ans = ans * pos2 % mod * binpow(neg, mod-2) % mod;
  }
  printf("%lld", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
