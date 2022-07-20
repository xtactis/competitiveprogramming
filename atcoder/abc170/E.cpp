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

const int N = 2e5;
const int sqN = 448;

int r[N], b[sqN], where[N];
set<pair<int, int>> s[N];

void solve() {
  int n, q; scanf("%d%d", &n, &q);
  for (int b, i = 0; i < n; ++i) {
    scanf("%d%d", r+i, &b);
    s[b-1].emplace(r[i], i);
    where[i] = b-1;
  }
  for (int i = 0; i < sqN; ++i) b[i] = 2e9;
  for (int i = 0; i < N; ++i) {
    if (s[i].empty()) continue;
    b[i/sqN] = min(b[i/sqN], s[i].rbegin()->first);
  }
  for (int i = 0; i < sqN; ++i)
    if (b[i] == 2e9)
      b[i] = -1;
  for (int c, d, i = 0; i < q; ++i) {
    scanf("%d%d", &c, &d);
    --c; --d;
    s[where[c]].erase({r[c], c});
    int w = where[c]/sqN;
    b[w] = 2e9;
    for (int j = w*sqN, lim = min(j+sqN, N); j < lim; ++j) {
      if (s[j].empty()) continue;
      b[w] = min(b[w], s[j].rbegin()->first);
    }
    if (b[w] == 2e9) b[w] = -1;
    where[c] = d;
    s[d].emplace(r[c], c);
    w = d/sqN;
    b[w] = 2e9;
    for (int j = w*sqN, lim = min(j+sqN, N); j < lim; ++j) {
      if (s[j].empty()) continue;
      b[w] = min(b[w], s[j].rbegin()->first);
    }
    int ans = 2e9;
    for (int i = 0; i < sqN; ++i) {
      if (b[i] == -1) continue;
      ans = min(ans, b[i]);
    }
    printf("%d\n", ans);
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
