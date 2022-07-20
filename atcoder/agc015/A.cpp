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

void solve() {
  int n, a, b; scanf("%d%d%d", &n, &a, &b);
  if (a > b) {
    printf("0");
    return;
  }
  if (n == 1 && a != b) {
    printf("0");
    return;
  }
  long long big = (long long)b*(n-1)+a, small = (long long)a*(n-1)+b;
  printf("%lld", big-small+1);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
