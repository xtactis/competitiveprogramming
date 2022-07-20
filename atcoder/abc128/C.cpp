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

const int N = 12;

int p[N], n, m;
vector<int> b[N];

bool check(int s) {
  for (int i = 0; i < m; ++i) {
    int count = 0;
    for (int e: b[i]) {
      if (s & (1 << e)) count = !count;
    }
    if (count != p[i]) return false;
  }
  return true;
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int k; scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int s; scanf("%d", &s);
      b[i].push_back(--s);
    }
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", p+i);
  }
  int ans = 0;
  for (int s = 0; s < (1 << n); ++s) {
    if (check(s)) ++ans;
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
