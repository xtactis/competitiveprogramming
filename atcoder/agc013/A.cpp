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

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int f = 0;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i-1]) {
      if (f == -1) {
	f = 0;
      }	else if (f == 0) {
	f = 1;
	++ans;
      }
    } else if (a[i] < a[i-1]) {
      if (f == 1) {
	f = 0;
      } else if (f == 0) {
	f = -1;
	++ans;
      }
    }
  }
  if (!f) ++ans;
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
