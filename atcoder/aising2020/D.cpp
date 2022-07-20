#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int f(int x) {
  int ret = 0;
  while (x) {
    x %= __builtin_popcount(x);
    ++ret;
  }
  return ret;
}

int binpow(long long b, long long e, int mod) {
  if (!e) return 1;
  if (e%2) return b*binpow(b, e-1, mod)%mod;
  return binpow(b*b%mod, e/2, mod);
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') ++cnt;
  }
  int x1 = 0, x0 = 0;
  for (int i = 0; i < n; ++i) {
    (x0 *= 2) %= (cnt+1);
    if (cnt > 1) (x1 *= 2) %= (cnt-1);
    if (s[i] == '0') continue;
    (x0 += 1) %= (cnt+1);
    if (cnt > 1) (x1 += 1) %= (cnt-1);
  }
  for (int p, x, i = 0; i < n; ++i) {
    if (s[i] == '1') {
      if (cnt == 1) {
	cout << "0\n";
	continue;
      }
      p = binpow(2, n-i-1, cnt-1);
      x = (x1-p+cnt-1) % (cnt-1);
    } else {
      p = binpow(2, n-i-1, cnt+1);
      x = (x0+p) % (cnt+1);
    }
    cout << 1+f(x) << "\n";
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
