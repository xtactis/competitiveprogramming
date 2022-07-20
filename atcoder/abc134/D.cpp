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

void rek(int i) {
  
}

const int N = 2e5+23;

int a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  vector<int> b;
  for (int i = n; i >= 1; --i) {
    if (!a[i]) continue;
    b.push_back(i);
    for (int j = 1; j*j <= i; ++j) {
      if (i%j) continue;
      a[j] = !a[j];
      if (i/j == j) continue;
      a[i/j] = !a[i/j];
    }
  }
  printf("%d\n", b.size());
  for (int e: b) printf("%d ", e);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
