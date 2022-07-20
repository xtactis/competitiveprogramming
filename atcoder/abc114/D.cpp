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

int h[123];
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void factorize(int x) {
  for (int p: primes) {
    for (int P = p; x % P == 0; P *= p) {
      ++h[p];
    }
  }
}

long long rek(int start, int sf = 75) {
  if (sf == 1) return 1;
  long long ret = 0;
  for (int i = start; i < primes.size(); ++i) {
    for (int j = 1; j <= h[primes[i]]; ++j) {
      if (sf % (j+1)) continue;
      ret += rek(i+1, sf / (j+1));
    }
  }
  return ret;
}

void solve() {
  int n; scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    factorize(i);
  }
  printf("%lld", rek(0));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
