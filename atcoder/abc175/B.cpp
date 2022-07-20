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

const int N = 123;

int l[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", l+i);
  int ans = 0;
  for (int i = 0; i < n-2; ++i) {
    for (int j = i+1; j < n-1; ++j) {
      if (l[i] == l[j]) continue;
      for (int k = j+1; k < n; ++k) {
	if (l[i] == l[k] || l[j] == l[k]) continue;
	if (l[i]+l[j] > l[k] &&
	    l[j]+l[k] > l[i] &&
	    l[k]+l[i] > l[j]) {
	  ++ans;
	}
      }
    }
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
