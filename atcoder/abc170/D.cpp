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

const int N = 1e6+23;

vector<int> v[N];
map<int, int> m;

void solve() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j+=i) {
      v[j].push_back(i);
    }
  }
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a; scanf("%d", &a);
    ++m[a];
  }
  int ans = 0;
  for (const auto &p: m) {
    if (p.second > 1) continue;
    bool found = false;
    for (int e: v[p.first]) {
      if (e == p.first) continue;
      if (m.count(e)) {
	found = true;
	break;
      }
    }
    if (!found) ++ans;
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
