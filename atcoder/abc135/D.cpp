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

string s;
int dp[N][13];

int rek(int pos, int m) {
  if (pos == s.size()) return m == 5;
  if (s[pos] != '?') return rek(pos+1, (m*10+s[pos]-'0')%13);
  int &ret = dp[pos][m];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 0; i <= 9; ++i) {
    ret = (ret+rek(pos+1, (m*10+i)%13))%mod;
  }
  return ret;
}

void solve() {
  cin >> s;
  int m = 0;
  memset(dp, -1, sizeof(dp));
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
