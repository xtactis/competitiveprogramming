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

const int N = 25;

long long a[N][N];
long long v[N], h[N];

void solve() {
  int n; scanf("%d", &n);
  long long x = -1, y = (n-1)*2-1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (i == j) a[i][j] = 0;
      else if (j-i == 1) {
	if (x == -1) {
	  a[i][j] = 0;
	  ++x;
	} else {
	  a[i][j] = 1LL << x++;
	}
	a[j][i] = 1LL << x++;
      } else {
	a[i][j] = a[j][i] = 1LL << y++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%lld ", a[i][j]);
    }
    printf("\n");
    fflush(stdout);
  }
  debug(x);
  debug(y);
  int q; scanf("%d", &q);
  while (q--) {
    long long k; scanf("%lld", &k);
    x = 0; int i = 0, j = 0;
    while (!(i == n-1 && j == n-1)) {
      printf("%d %d\n", i+1, j+1);
      fflush(stdout);
      if (j < n-1 && k & a[i][j+1]) ++j;
      else if (i < n-1 && k & a[i+1][j]) ++i;
      else if (a[i+1][j] == 0) ++i;
      else ++j;
    }
    printf("%d %d\n", i+1, j+1);
    fflush(stdout);
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
