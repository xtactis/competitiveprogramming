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

const int N = 2e5+34;
const int mod = 2019;

string s;
long long t[N];
int h[mod];

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

void solve() {
  cin >> s;
  const int n = s.size();
  ++h[0];
  for (int i = n-1; i >= 0; --i) {
    t[i] = (t[i+1] + binpow(10, n-i) * (s[i]-'0')) % mod;
    ++h[t[i]];    
  }
  long long ans = 0;
  for (int i = 0; i < mod; ++i) {
    ans += (long long)h[i]*(h[i]-1)/2;
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
