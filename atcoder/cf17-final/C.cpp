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

int h[25];
int n;

void solve() {
  scanf("%d", &n);
  ++h[0];
  bool zero = false;
  for (int d, i = 0; i < n; ++i) {
    scanf("%d", &d);
    if (++h[d] == 3) {
      puts("0");
      return;
    }
  }
  if (h[0] >= 2 || h[12] >= 2) {
    puts("0");
    return;
  }
  bool left = true;
  for (int i = 1; i < 12; ++i) {
    if (h[i] == 2) {
      --h[i]; ++h[24-i];
    } else if (h[i] == 1) {
      if (left) left = false;
      else {
	--h[i]; ++h[24-i];
	left = true;
      }
    }
  }
  int ans = 1e9;
  for (int i = 0; i < 24; ++i) {
    if (!h[i]) continue;
    for (int j = i+1; j <= 24; ++j) {
      if (!h[j]) continue;
      int d = j-i;
      ans = min(ans, min(d, 24-d));
    }
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
