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

const int N = 1e6+23;

int h[N], H[N];

void solve() {
  int n; scanf("%d", &n);
  int g; scanf("%d", &g);
  ++h[g];
  for (int a, i = 1; i < n; ++i) {
    scanf("%d", &a);
    ++h[a];
    g = __gcd(g, a);
  }
  if (g != 1) {
    puts("not coprime");
    return;
  }
  for (int i = 2; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      H[i] += h[j];
    }
    if (H[i] > 1) {
      puts("setwise coprime");
      return;
    }
  }
  puts("pairwise coprime");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
