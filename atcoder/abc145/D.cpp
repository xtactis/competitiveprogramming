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

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

int C(int n, int k) {
  long long res = 1;
  for (int i = n-k+1; i <= n; ++i) {
    (res *= i) %= mod;
  }
  for (int i = 2; i <= k; ++i) {
    (res *= binpow(i, mod-2)) %= mod;
  }
  return res;
}

void solve() {
  int x, y; scanf("%d%d", &x, &y);
  if ((x+y)%3) {
    puts("0");
    return;
  }
  int r = (x+y)/3;
  int c = x-r;
  if (c < 0) {
    puts("0");
    return;
  }
  printf("bruh%d", C(r, c));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
