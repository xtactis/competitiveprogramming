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

const int N = 3e5+23;

vector<pair<int, int>> v;
int H[N], W[N];

void solve() {
  int h, w, m; scanf("%d%d%d", &h, &w, &m);
  int a = 0, b = 0;
  for (int i = 0; i < m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    v.emplace_back(--x, --y);
    ++H[x];
    a = max(a, H[x]);
    ++W[y];
    b = max(b, W[y]);
  }
  int cnt = 0;
  for (const auto &e: v) {
    cnt += (H[e.first]+W[e.second]) == (a+b);
  }
  int cntH = 0, cntW = 0;
  for (int i = 0; i < h; ++i)
    cntH += (H[i] == a);
  for (int i = 0; i < w; ++i)
    cntW += (W[i] == b);
  if (1LL*cntH*cntW > cnt)
    printf("%d", a+b);
  else
    printf("%d", a+b-1);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
