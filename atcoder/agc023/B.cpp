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

const int N = 321;
const int P = 31;
const int m = 1e9+9;

char A[N][N];
long long p[2*N], h[2*N][2*N], v[2*N][2*N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf(" %c", A[i]+j);
      A[i][j] -= 'a'-1;
    }
  }
  p[0] = 1;
  for (int i = 1; i < 2*n; ++i)
    p[i] = (p[i-1] * P) % m;
  for (int i = 0; i < 2*n; ++i) {
    for (int j = 0; j < 2*n; ++j) {
      h[i][j+1] = (h[i][j] + A[i%n][j%n] * p[j]) % m;
      v[i][j+1] = (v[i][j] + A[j%n][i%n] * p[j]) % m;
    }
  }
  int ans = 0;
  for (int a = 0; a < n; ++a) {
    for (int b = 0; b < n; ++b) {
      for (int i = 0; i < n; ++i) {
	long long H = (h[i+a][b+n]-h[i+a][b]+m)%m,
	  V = (v[i+b][a+n]-v[i+b][a]+m)%m;
	if (a < b) {
	  V = V*p[b-a]%m;
	} else if (b < a) {
	  H = H*p[a-b]%m;
	}
	if (H != V) goto bad;
      }
      ++ans;
    bad:;
    }
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
