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

const int N = 53;

int a[N], h[27];

void solve() {
  string s; cin >> s;
  for (int i = 0; i < (int)s.size(); ++i) {
    ++h[s[i]-'a'];
  }
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int c = 0;
  while (!h[c]) ++c;
  string ans(n);
  int p = max_element(a, a+n)-a;
  ans[p] = c+'a';
  --h[c];
  for (int i = 1; i < n; ++i) {
    while (!h[c]) ++c;
    for (int j = 0; j < n; ++j) {
      
    }
  }
}

int main() {
  init();
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
