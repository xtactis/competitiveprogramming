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

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  vector<int> v[m];
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    v[x%m].push_back(x);
  }
  int ans = v[0].size()/2, lim = m/2;
  if (m%2==0) {
    --lim;
    ans += v[m/2].size()/2;
  }
  for (int i = 1; i <= lim; ++i) {
    auto &s = v[i], &t = v[m-i];
    if (s.size() < t.size()) swap(s, t);
    sort(s.begin(), s.end());
    int cur = 0;
    for (int j = 0; j < (int)s.size()-1 && (int)s.size()-2*(cur+1) >= (int)t.size(); ++j) {
      if (s[j] == s[j+1]) {
	++cur;
	++j;
      }
    }
    ans += t.size()+cur;
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
