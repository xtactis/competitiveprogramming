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

const int N = 5e3+23;

char s[N];
int z[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c", s+i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    debug(i);
    for (int j = 1, l = 0, r = 0; j < n-i; ++j) {
      if (j <= r) z[j] = min(r-j+1, z[j-l]);
      while (j+z[j] < n-i && s[i+z[j]] == s[i+j+z[j]]) ++z[j];
      if (j+z[j]-1 > r) l = j, r = j+z[j]-1;
      if (z[j] <= j) ans = max(ans, z[j]);
    }
    for (int i = 0; i < n; ++i) z[i] = 0;
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
