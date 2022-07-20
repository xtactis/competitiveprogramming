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
  int n, k; scanf("%d%d", &n, &k);
  vector<long long> v;
  for (int i = 0; i < n; ++i) {
    long long x; scanf("%lld", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  long long sum = 0;
  for (int i = n-2; k && i >= 0; --i) {
    if (!v[i]) break;
    --k;
    v.back() += v[i];
    v[i] = 0;
  }
  printf("%lld\n", v.back()-*min_element(v.begin(), v.end()));
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
