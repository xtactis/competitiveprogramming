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

const int N = 5e5+23;

pair<pair<int, int>, int> qs[N];
int c[N], f[N], last[N], ans[N], bit[N], n, q;

void add(int idx, int val) {
  for (; idx <= n; idx += idx & -idx)
    bit[idx] += val;
}

int sum(int r) {
  int ret = 0;
  for (; r > 0; r-=r&-r)
    ret += bit[r];
  return ret;
}

int sum(int l, int r) {
  return sum(r+1) - sum(l);
}

void solve() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", c+i);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &qs[i].first.first, &qs[i].first.second);
    --qs[i].first.first;
    --qs[i].first.second;
    qs[i].second = i;
  }
  sort(qs, qs+q, [](const auto &x, const auto &y){
    return x.first.second < y.first.second;
  });
  int qq = 0;
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; ++i) {
    if (last[c[i]] != -1)
      add(last[c[i]]+1, -1);
    last[c[i]] = i;
    add(i+1, 1);
    while (qq < q && qs[qq].first.second == i) {
      ans[qs[qq].second] = sum(qs[qq].first.first, qs[qq].first.second);
      ++qq;
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
