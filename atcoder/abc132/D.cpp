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

const int mod = 1e9+7;

int binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return binpow(b, e-1)*b%mod;
  return binpow(b*b%mod, e/2);
}

int mul(long long a, long long b) {
  return a*b%mod;
}

int nCr(long long n, long long r) {
  n = n+r-1;
  long long res = 1;
  for (int i = n-r+1; i <= n; ++i) {
    res = res*i%mod;
  }
  for (int i = 2; i <= r; ++i) {
    res = res*binpow(i, mod-2)%mod;
  }
  return res;
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; ++i) {
    int nB = k-i, nR = (n-k)-(i-1);
    int bB = i, bR = i+1;
    if (nR < 0) {
      printf("0\n");
      continue;
    }
    printf("%d\n", mul(nCr(bB, nB), nCr(bR, nR)));
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
