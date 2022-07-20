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

void solve() {
  int n; scanf("%d", &n);
  const auto comp =  [](const pair<int, int> &x, const pair<int, int> &y) {
		       if (x.second-x.first == y.second-y.first) return x.first < y.first;
		       return x.second-x.first > y.second-y.first;
		     };
  const auto ccomp = [&comp](const pair<int, int> &x, const pair<int, int> &y) {
		       return !comp(x, y);
		     };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(ccomp)> q(ccomp);
  vector<int> a(n+1);
  q.emplace(1, n);
  int i = 0;
  while (q.size()) {
    auto p = q.top(); q.pop();
    int pos = (p.second+p.first-1)/2;
    if ((p.second-p.first+1)%2) {
      pos = (p.second+p.first)/2;
    }
    if (a[pos]) continue;
    a[pos] = ++i;
    if (p.second-p.first < 0) continue;
    q.emplace(p.first, pos-1);
    q.emplace(pos+1, p.second);
  }
  //a[n] = n;
  for (int i = 1; i <= n; ++i) {
    printf("%d ", a[i]);
  }
  puts("");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
