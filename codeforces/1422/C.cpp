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

const int N = 1e5+23;
const int mod = 1e9+7;

string s;
long long r[N], t[N], l[N];
int n;

void solve() {
  cin >> s;
  n = s.size();
  l[0] = s[0]-='0';
  t[0] = 1;
  for (int i = 1; i < n; ++i) {
    l[i] = (l[i-1]*10%mod + (s[i]-='0')) % mod;
    t[i] = t[i-1]*10%mod;
  }
  for (int i = n-1; i >= 0; --i) {
    r[i] = (s[i]*t[n-1-i]%mod+r[i+1])%mod;
  }
  t[n] = 1;
  long long x = 1;
  for (int i = n-1; i >= 0; --i) {
    x = x*10%mod;
    t[i] = x;
  }
  for (int i = 1; i < n; ++i) {
    l[i] = (l[i] + l[i-1]) % mod;
  }
  long long ans = 0;
  for (int i = n; i > 0; --i) {
    ans = (ans + r[i]*i%mod) % mod;
    if (i > 1) ans = (ans + t[i]*l[i-2]%mod) % mod;
  }
  cout << ans;
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
