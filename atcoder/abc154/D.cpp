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
int p[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
  }
  double sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += (p[i]+1)/2.;
  }
  double ans = sum;
  for (int i = k; i < n; ++i) {
    sum -= (p[i-k]+1)/2.;
    sum += (p[i]+1)/2.;
    ans = max(ans, sum);
  }
  printf("%.6lf", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
