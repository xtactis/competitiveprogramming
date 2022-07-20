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

bool solve() {
  int h, w, n; scanf("%d%d%d", &h, &w, &n);
  int sr, sc; scanf("%d%d", &sr, &sc);
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
  int z[4] = {0, 0, 0, 0};
  ++z[s[n-1]];
  --sc; --sr;
  for (int i = n-2; i >= 0; --i) {
    int other = t[i]+1;
    if (t[i]%2) other = t[i]-1;
    z[other] = max(z[other]-1, 0);
    ++z[s[i]];
    if (z[0] >= w-z[1] || z[2] >= h-z[3]) return true;
  }
  return z[0] > sc || w-z[1] <= sc || z[2] > sr || h-z[3] <= sr;
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    puts(!solve()?"YES":"NO");
  }
  return 0;
}
