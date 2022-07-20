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
const int mod = 1e9+7;

int n, m;
int a[N], b[N];
long long dp[N][2];

long long rek(int i, int g) {
  if (i >= n) return g;
  long long &ret = dp[i][g];
  if (ret != -1) return ret;
  if (a[i] && b[i]) {
    if (a[i] < b[i] && !g) return 0;
    if (a[i] == b[i]) return ret = rek(i+1, g);
    return ret = rek(i+1, 1);
  }
  if (a[i] && !b[i]) {
    ret = (a[i]-1)*rek(i+1, 1)%mod;
    ret = (ret + rek(i+1, g))%mod;
    if (g) ret = (ret + (m-a[i])*rek(i+1, 1)%mod)%mod;
  } else if (!a[i] && b[i]) {
    ret = (m-b[i])*rek(i+1, 1)%mod;
    ret = (ret + rek(i+1, g))%mod;
    if (g) ret = (ret + (b[i]-1)*rek(i+1, 1)%mod)%mod;
  } else {
    long long s = 1LL*m*(m-1)/2;
    ret = s*rek(i+1, 1)%mod;
    ret = (ret + m*rek(i+1, g)%mod)%mod;
    if (g) ret = (ret + s*rek(i+1, 1)%mod)%mod;
  }
  return ret;
}

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &n, &m);
  long long total = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (!a[i]) total = total*m%mod;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
    if (!b[i]) total = total*m%mod;
  }
  long long good = rek(0, 0);
  printf("%lld", good*binpow(total, mod-2)%mod);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
