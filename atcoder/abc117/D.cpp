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

const int N = 1e5+23;
const int B = 40;

long long a[N];
int h[B];
int ind[B];
int n;
long long k;


void solve() {
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    for (int j = 0; j < B; ++j) {
      if (a[i] & (1LL << j))
	++h[j];
    }
  }
  long long x = 0;
  for (int i = B-1; i >= 0; --i) {
    if (h[i] > n-h[i]) continue;
    if (x + (1LL << i) > k) continue;
    x += 1LL << i;
  }
  debug(x);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += x ^ a[i];
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
