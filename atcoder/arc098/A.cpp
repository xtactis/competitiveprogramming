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

const int N = 3e5+23;

char a[N];
int e[N], w[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c", a+i);
    if (i) e[i] = e[i-1];
    if (a[i] == 'W') ++e[i];
  }
  int ans = n;
  for (int i = n-1; i >= 0; --i) {
    w[i] = w[i+1];
    if (a[i] == 'E') ++w[i];
    ans = min(ans, e[i-1]+w[i+1]);
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
