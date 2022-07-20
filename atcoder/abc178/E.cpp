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

pair<long long, long long> a[N];
int n;

int closest(int x, int y) {
  long long d = 2e9;
  int ret = -1;
  for (int i = 0; i < n; ++i) {
    long long nd = abs(x-a[i].first)+abs(y-a[i].second);
    if (nd < d) {
      d = nd;
      ret = i;
    }
  }
  return ret;
}

void solve() {
  scanf("%d", &n);
  long long maX = -1e9, maY = -1e9, miX = 1e9, miY = 1e9;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    maX = max(maX, a[i].first);
    miX = min(miX, a[i].first);
    maY = max(maY, a[i].second);
    miY = min(maY, a[i].second);
  }
  int corners[8] = {closest(miX, maY), closest(maX, maY),
		    closest(miX, miY), closest(maX, miY),
                    closest(0  , maY), closest(0  , miY),
		    closest(maX, 0  ), closest(miX, 0  )};
  long long ans = 0;
  for (int i = 0; i < 7; ++i) {
    for (int j = i+1; j < 8; ++j) {
      if (corners[i] == corners[j]) continue;
      long long nd = abs(a[corners[j]].first-a[corners[i]].first)+
	             abs(a[corners[j]].second-a[corners[i]].second);
      ans = max(nd, ans);
    }
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
