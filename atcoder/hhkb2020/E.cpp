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

const int N = 2e3+23;
const int mod = 1e9+7;

int h, w;
int a[N][N], hc[N][N], vc[N][N], bof[N][N];

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

void solve() {
  scanf("%d%d", &h, &w);
  int tot = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c; scanf(" %c", &c);
      if (c == '#') continue;
      ++tot;
      vc[i][j] = hc[i][j] = a[i][j] = 1;
      if (i && a[i-1][j]) vc[i][j] += vc[i-1][j];
      if (j && a[i][j-1]) hc[i][j] += hc[i][j-1];
    }
  }
  for (int i = h-1; i >= 0; --i) {
    int m = 0;
    for (int j = w-1; j >= 0; --j) {
      if (hc[i][j] == 0) {
	m = 0;
	continue;
      }
      m = max(hc[i][j], m);
      bof[i][j] = m;
    }
  }
  for (int j = w-1; j >= 0; --j) {
    int m = 0;
    for (int i = h-1; i >= 0; --i) {
      if (vc[i][j] == 0) {
	m = 0;
	continue;
      }
      m = max(vc[i][j], m);
      bof[i][j] += m-1;
    }
  }
  long long ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!bof[i][j]) continue;
      ans = (ans + (binpow(2, bof[i][j])-1+mod)%mod * binpow(2, tot-bof[i][j]) % mod) % mod;
    }
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
