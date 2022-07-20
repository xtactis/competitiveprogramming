#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

const long long mod = 1e9+7;
const int N = 1e6+23;

long long a[N], p[N], bp[N];
string s;
int n;

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

void print(int x, int y) {
  for (int i = 0; i < n; ++i) {
    cout << s[i];
    if (x == i) cout << '+';
    if (y == i) cout << '=';
  }
}

long long h(int i, int j) {
  return (a[j]-a[i]*p[j-i]%mod+mod)%mod;
}

void solve() {
  cin >> s;
  n = s.size();
  a[0] = s[0]-'0';
  p[0] = 1;
  for (int i = 1; i < n; ++i) {
    p[i] = p[i-1]*10%mod;
    a[i] = (a[i-1]*10+s[i]-'0') % mod;
  }
  for (int i = 0; i < 2*n/3-1; ++i) {
    for (int j = max(n/2-1, i+1); j < 2*n/3; ++j) {
      if ((a[i]+h(i, j))%mod == h(j, n-1)) {
	print(i, j);
	return;
      }
    }
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
