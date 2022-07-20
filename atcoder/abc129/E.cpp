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
const int N = 1e5+23;

int n;
string l;

long long dp[N][2];

long long rek(int pos, int f) {
  if (pos == n) return 1;
  long long &ret = dp[pos][f];
  if (ret != -1) return ret;
  ret = 0;
  int lmt = f?1:(l[pos]-'0');
  for (int i = 0; i <= lmt; ++i) {
    int nf = f;
    if (f == 0 && i < lmt) nf = 1;
    long long tmp = rek(pos+1, nf);
    if (i == 1) tmp = tmp*2%mod;
    ret = (ret + tmp) % mod;
  }
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> l;
  n = l.size();
  cout << rek(0, 0);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
