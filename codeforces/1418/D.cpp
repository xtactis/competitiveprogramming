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

int a[N];

set<int> s;
map<int, int> ms;
pair<int, int> qq[N];

void solve() {
  int n, q; scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    s.insert(a[i]);
  }
  sort(a, a+n);
  ++ms[0];
  for (int i = 1; i < n; ++i) {
    ++ms[a[i]-a[i-1]];
  }
  printf("%d\n", (*s.rbegin()-*s.begin())-ms.rbegin()->first);
  for (int t, x, i = 0; i < q; ++i) {
    scanf("%d%d", &t, &x);
    if (t) {
      auto e = s.insert(x).first;
      auto f = e; --f;
      auto g = e; ++g;
      debug(*e);
      if (e != s.begin() && g != s.end()) {
	int t = *g-*f;
	if (!--ms[t]) ms.erase(t);
      }
      if (g != s.end()) {
	int t = *g-*e;
	++ms[t];
      }
      if (e != s.begin()) {
	int t = *e-*f;
	++ms[t];
      }
    } else {
      const auto e = s.find(x);
      auto f = e; --f;
      auto g = e; ++g;
      debug(*e);
      if (e != s.begin() && g != s.end()) {
	int t = *g-*f;
	++ms[t];
      }
      if (g != s.end()) {
	int t = *g-*e;
	if (!--ms[t]) ms.erase(t);
      }
      if (e != s.begin()) {
	int t =  *e-*f;
	if (!--ms[t]) ms.erase(t);
      }
      s.erase(x);
    }
    if (s.size() && ms.size()) printf("%d\n", (*s.rbegin()-*s.begin())-ms.rbegin()->first);
    else puts("0");
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
