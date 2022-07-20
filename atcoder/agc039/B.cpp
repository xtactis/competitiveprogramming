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

const int N = 234;
vector<int> g[N];
int bio[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c; scanf(" %c", &c);
      if (c == '1') {
	g[i].push_back(j);
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) bio[j] = 0;
    int cur = 0;
    queue<pair<int, int>> q;
    q.emplace(i, 1);
    bio[i] = 1;
    while (!q.empty()) {
      const auto &p = q.front();
      cur = p.second;
      for (int v: g[p.first]) {
	if (bio[v]) {
	  if (bio[v] != p.second-1 && bio[v] != p.second+1) goto bad;
	  continue;
	}
	q.emplace(v, p.second+1);
	bio[v] = p.second+1;
      }
      q.pop();
    }
    ans = max(ans, cur);
  bad:;
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
