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

long long nCk(long long n, long long k) {
  long long ret = 1;
  if (k > n-k) k = n-k;
  for (int i = n-k+1; i <= n; ++i) {
    ret *= i;
  }
  for (int i = 2; i <= k; ++i) {
    ret /= i;
  }
  return ret;
}

void solve() {
  int n, p; scanf("%d%d", &n, &p);
  int o = 0;
  for (int i = 0; i < n; ++i) {
    int a; scanf("%d", &a);
    o += a%2;
  }
  long long ansodd = 0;
  for (int i = p; i <= o; i+=2) {
    ansodd += nCk(o, i);
  }
  printf("%lld", ansodd << (n-o));

}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
