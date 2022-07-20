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

const int N = 1e5+23;
const long long inf = 1e15;

struct Move {
  int l, r, c, ind;
};

vector<Move> v;
long long d[N];
pair<int, int> rs[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int l, r, c, i = 0; i < m; ++i) {
    scanf("%d%d%d", &l, &r, &c);
    v.push_back({l-1, r-1, c, i});
    rs[i] = {r-1, i};
  }
  d[0] = 0;
  for (int i = 1; i < n; ++i) d[i] = inf;
  sort(v.begin(), v.end(), [](const Move &x, const Move &y){return x.l < y.l;});
  sort(rs, rs+m);
  int r = 0;
  set<pair<long long, int>> s;
  map<int, long long> mp;
  for (int l = 0, i = 0; i < n; ++i) {
    if (s.size() == 0 && d[i] == inf) {
      puts("-1");
      return;
    }
    if (s.size())
      d[i] = min(d[i], s.begin()->first);
    for (; l < m && v[l].l == i; ++l) {
      d[v[l].r] = min(d[v[l].r], d[i]+v[l].c);
      s.emplace(d[i]+v[l].c, v[l].r);
      mp[v[l].ind] = d[i]+v[l].c;
    }
    for (; r < m && rs[r].first == i; ++r) {
      s.erase({mp[rs[r].second], i});
    }
  }
  printf("%lld", d[n-1]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
