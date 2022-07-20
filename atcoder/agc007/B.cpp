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

const int N = 2e4+23;

int p[N], a[N], b[N];

void solve() {
  int n; scanf("%d", &n);
  for (int x, i = 0; i < n; ++i) {
    scanf("%d", &x);
    p[x-1] = i+1;
  }
  a[0] = 1;
  printf("1 ");
  for (int i = 1; i < n; ++i) {
    a[i] = a[i-1]+1;
    if (p[i] > p[i-1]) a[i] += p[i]-p[i-1];
    printf("%d ", a[i]);
  }
  puts("");
  b[n-1] = 1;
  for (int i = n-2; i >= 0; --i) {
    b[i] = b[i+1]+1;
    if (p[i] > p[i+1]) b[i] += p[i]-p[i+1];
  }
  for (int i = 0; i < n; ++i) printf("%d ", b[i]);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
