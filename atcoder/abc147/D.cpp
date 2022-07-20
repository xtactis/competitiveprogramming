#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+1;
const int mod = 1e9+7;

long long b[61][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    long long a; scanf("%lld", &a);
    for (int j = 0; j <= 60; a>>=1, ++j) {
      ++b[j][a&1];
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 60; ++i) {
    ans += b[i][0]*b[i][1] % mod * ((1LL<<i) % mod) % mod;
    ans %= mod;
  }
  printf("%lld", ans);
  
  return 0;
}
