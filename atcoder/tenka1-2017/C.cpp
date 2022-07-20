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

long long N;

bool check(long long h, long long n, long long w) {
  return 4*h*n*w == N*(n*w+h*w+h*n);
}

void solve() {
  scanf("%lld", &N);
  for (long long h = 1; h <= 3500; ++h) {
    for (long long n = 1; n <= 3500; ++n) {
      if (4*h*n-N*n-N*h == 0) continue;
      long long w = N*h*n/(4*h*n-N*n-N*h);
      if (w <= 0) continue;
      if (check(h, n, w)) {
	printf("%lld %lld %lld\n", h, n, w);
	return;
      }
    }
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
