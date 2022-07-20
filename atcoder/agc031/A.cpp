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

vector<int> a[30];

void solve() {
  int n; string s; cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    a[s[i]-'a'].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int skip = s[i]-'a';
    long long cur = 1;
    for (int j = 0; j < 26; ++j) {
      if (j == skip) continue;
      if (a[j].empty()) continue;
      int x = a[j].size()-(lower_bound(a[j].begin(), a[j].end(), i)-a[j].begin());
      if (!x) continue;
      (cur *= x+1) %= mod;
      //(cur += x) %= mod;
    }
    (ans += cur) %= mod;
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
