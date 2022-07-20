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

int a[N], skipped[N];
stack<int> ans;

void solve() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int cnt = 0; cnt < n; ++cnt) {
    int sel = -1;
    for (int i = 1, ind = 1; i <= n; ++i) {
      if (skipped[i]) continue;
      if (a[i] == ind) {
	if (sel == -1 || a[i] > a[sel]) sel = i;
      }
      ++ind;
    }
    if (sel == -1) {
      printf("-1");
      return;
    }
    skipped[sel] = true;
    ans.push(a[sel]);
  }
  while (!ans.empty()) {
    printf("%d\n", ans.top());
    ans.pop();
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
