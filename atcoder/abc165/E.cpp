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

const int N = 2e5+23;

bool bio[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  vector<pair<int, int>> ans;
  set<int> unused;
  for (int i = 1; i <= m; ++i) {
    unused.insert(2*m-i+1-i);
    if (2*m-i+1-i == n+1-(2*m-i+1)) continue;
    bio[i] = 1; bio[2*m-i+1] = 1;
    unused.erase(2*m-i+1-i);
    ans.emplace_back(i, 2*m-i+1);
  }
  if (ans.size() != m) {
    
  }
  for (const auto &e: ans) printf("%d %d\n", e.first, e.second);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
