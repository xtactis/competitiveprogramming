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

const int N = 123;

int h[N];

void solve() {
  int n; scanf("%d", &n);
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    ++h[a];
  }
  int left = -1, right = -1;
  for (int i = 0; i < N; ++i) {
    if (h[i] < 2 && left == -1) left = i;
    if (h[i] < 1 && right == -1) right = i;
    h[i] = 0;
  }
  debug(left);
  debug(right);
  printf("%d\n", left+right);
}

int main() {
  init();
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
