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

string s;
int n, m;

void solve() {
  cin >> n >> m;
  cin >> s;
  vector<int> ans;
  for (int i = n; i > 0;) {
    int cur = 0, j = min(m, i);
    for (; j >= 0; --j) {
      if (s[i-j] == '1') continue;
      cur = j;
      break;
    }
    if (cur == 0) {
      cout << -1;
      return;
    }
    i -= j;
    ans.push_back(cur);
  }
  for (int i = (int)ans.size()-1; i >= 0; --i)
    cout << ans[i] << ' ';
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
