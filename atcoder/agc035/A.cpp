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

int h[31];

void solve() {
  int n; scanf("%d", &n);
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    for (int j = 0; j <= 30; ++j) {
      if (a & (1 << j)) ++h[j];
    }
  }
  for (int i = 0; i < 31; ++i) {
    if (h[i]&1) {
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
