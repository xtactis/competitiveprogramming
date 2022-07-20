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

set<long long> v;

void dfs(int i, long long prev=0) {
  if (prev > 3234566667LL) {
    return;
  }
  if (prev) v.insert(prev);
  if (i-1 >= 0) dfs(i-1, prev*10+(i-1));
  if (i != 0 || prev != 0) dfs(i, prev*10+i);
  if (i+1 < 10) dfs(i+1, prev*10+(i+1));
}

void solve() {
  int k; scanf("%d", &k);
  for (int i = 0; i < 10; ++i) {
    dfs(i);
  }
  for (auto e: v) {
    if (!--k) {
      printf("%lld", e);
    }
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
