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

int a[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  int zero = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (a[i] == 0) { // real stupid
      --k; --n; --i;
      continue;
    }
    if (zero == -1 && a[i] > 0) zero = i;
  }
  if (zero == -1) zero = n;
  if (k == 0) {
    printf("0");
    return;
  }
  long long ans = 1e15;
  for (long long cur, cnt, i = 0; i < n; ++i) {
    if (a[i] < 0) {
      cnt = zero-i;
      cur = -a[i];
      if (cnt < k) {
	if (k+i-1 >= n) continue;
	cur += -a[i] + a[k+i-1];
      }
    } else {
      cnt = i-zero+1;
      cur = a[i];
      if (cnt < k) {
	if (i-k+1 < 0) continue;
	cur += a[i] + -a[i-k+1];
      }      
    }
    ans = min(ans, cur);
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
