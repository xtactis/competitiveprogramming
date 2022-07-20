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
  long long k, a, b; scanf("%lld%lld%lld", &k, &a, &b);
  if (b <= a || k+1 < a) {
    printf("%lld", k+1);
    return;
  }
  long long ans = k+1;
  k -= a-1;
  long long cur = k/2*b-(k/2-1)*a;
  if (k%2) ++cur;
  printf("%lld", max(ans, cur));
}
/*
48518828981938099
53513332169120811


a 0

0 1
b 0
(b-a) 1
(2b-a) 0
(2b-2a) 1
(3b-3a) 0
*/
int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
