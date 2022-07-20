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

const int N = 2e5+23;

pair<int, int> a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  sort(a, a+n, [](const pair<int, int> &x, const pair<int, int> &y) {
		 return x.second < y.second;
	       });
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i].first;
    if (cur > a[i].second) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
