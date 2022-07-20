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

int n;
pair<long long, long long> p[N];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &p[i].first, &p[i].second);
    p[i].first -= p[i].second-1;
    p[i].second = p[i].first+p[i].second*2-1;
  }
  sort(p, p+n, [](const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
  });
  long long prev = p[0].second;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (p[i].first > prev) {
      prev = p[i].second;
      ++ans;
    }
  }
  printf("%d\n", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
