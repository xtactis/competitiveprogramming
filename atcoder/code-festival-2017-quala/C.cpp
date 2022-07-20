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

int a[26];

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  int sum = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c; scanf(" %c", &c);
      ++a[c-'a'];
    }
  }
  if (h > 1 && w > 1) {
    for (int i = 0; i < 26; ++i) {
      sum += a[i] %= 4;
    }
    if (h%2) sum -= w;
    if (w%2) sum -= h;
    if (w%2 && h%2) ++sum;
    if (sum) {
      puts("No");
      return;
    }
  }
  int o = 0;
  for (int i = 0; i < 26; ++i) {
    if (a[i]%2) ++o;
  }
  if (o > 1) puts("No");
  else if (h%2 && w%2 && !o) puts("No");
  else if ((h%2 == 0 || w%2 == 0) && o) puts("No");
  else puts("Yes");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
