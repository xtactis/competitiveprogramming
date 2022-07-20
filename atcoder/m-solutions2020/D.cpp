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
  int n; scanf("%d", &n);
  int p;
  long long cur = 1000; 
  scanf("%d", &p);
  for (int a, i = 1; i < n; ++i) {
    scanf("%d", &a);
    if (a > p) {
      cur = cur/p*a+cur%p;
    }
    p = a;
  }
  printf("%lld", cur);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
