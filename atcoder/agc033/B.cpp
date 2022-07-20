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

int s[N], t[N];

void solve() {
  int h, w, n; scanf("%d%d%d", &h, &w, &n);
  int sr, sc; scanf("%d%d", &sr, &sc);
  int x[4] = {sc-1, w-sc, sr-1, h-sr};
  for (int i = 0; i < n; ++i) {
    scanf(" %c", s+i);
    if (s[i] == 'L') s[i] = 0;
    else if (s[i] == 'R') s[i] = 1;
    else if (s[i] == 'U') s[i] = 2;
    else s[i] = 3;
  }
  for (int i = 0; i < n; ++i) {
    scanf(" %c", t+i);
    if (t[i] == 'L') t[i] = 0;
    else if (t[i] == 'R') t[i] = 1;
    else if (t[i] == 'U') t[i] = 2;
    else t[i] = 3;
  }
  int z[4] = {}, y[4] = {};
  for (int i = n-1; i >= 0; --i) {
    if (y[t[i]] < x[t[i]]) {
      ++y[t[i]];
    } else {
      int other = t[i]+1;
      if (t[i]%2) other = t[i]-1;
      if (z[other]) --z[other];
    }
    int other = s[i]+1;
    if (s[i]%2) other = s[i]-1;
    if (y[other]) {
      --y[other];
    } else {
      ++z[s[i]];
      if (z[s[i]] > x[s[i]]) {
	puts("NO");
	return;
      }
    }
  }
  puts("YES");
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
