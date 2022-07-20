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
int a[N];
int h[21];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  long long ans = 0;
  long long i = 0, j = 0, cnt = 0, prev = 0;
  bool good;
  for (; i < n; ++i) {
    good = true;
    ++cnt;
    for (int b = 0; b < 21; ++b) {
      if (a[i] & (1<<b)) ++h[b];
      if (h[b] > 1) good = false;
    }
    if (good) continue;
    ans += cnt*(cnt-1)/2;
    ans -= prev*(prev+1)/2;
    while (!good) {
      good = true;
      --cnt;
      for (int b = 0; b < 21; ++b) {
	if (a[j] & (1<<b)) --h[b];
	if (h[b] > 1) good = false;
      }
      ++j;
    }
    prev = cnt-1;
  }
  ans += (cnt+1)*cnt/2;
  ans -= prev*(prev+1)/2;
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
