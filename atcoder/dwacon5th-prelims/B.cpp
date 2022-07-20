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

const int N = 1e3+23;

vector<long long> v;
long long a[N];
int skip[N*N], cnt[52];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    if (i) a[i] += a[i-1];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      v.push_back(a[j]);
      if (i) v.back() -= a[i-1];
    }
  }
  long long ans = 0;
  for (int i = 50; i >= 0; --i) {
    long long b = 1LL << i;
    int cnt = 0;
    for (int j = 0; j < (int)v.size(); ++j) {
      if (skip[j]) continue;
      if (v[j] & b) ++cnt;
    }
    if (cnt < k) continue;
    ans |= b;
    for (int j = 0; j < (int)v.size(); ++j) {
      if (v[j] & b) continue;
      skip[j] = 1;
    }
  }
  printf("%lld", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
