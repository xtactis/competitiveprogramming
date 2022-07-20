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
char s[N];

void solve() {
  int n; scanf("%d", &n);
  int w = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    scanf(" %c", s+i);
    if (s[i] == 'R') ++r;
    else ++w;
  }
  int ans = min(w, r);
  for (int i = 0, R = r; i < R; ++i) {
    if (s[i] == 'R') --r;
  }
  printf("%d", min(ans, r));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
