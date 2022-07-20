sa#include <bits/stdc++.h>
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

template<typename T>
struct FenwickTree {
  vector<T> bit;
  int n;
  
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  
  void add(int p, T v) {
    for (; p < n; p = p | (p+1))
      bit[p] += v;
  }
  
  int sum(int r) {
    T ret = 0;
    for (; r >= 0; r = (r & (r+1))-1)
      ret += bit[r];
    return ret;
  }
};

void solve() {
  int n, q; scanf("%d%d", &n, &q);
  long long ans = 1LL*(n-2)*(n-2);
  int m1x = n, m2x = n;
  FenwickTree<long long> f1(n), f2(n);
  f1.add(0, n); f2.add(0, n);
  while (q--) {
    int t, x; scanf("%d%d", &t, &x);
    debug(ans);
    if (t == 1) {
      long long y = f1.sum(x);
      debug(y);
      debug(m2x);
      if (m2x > x) {
	f2.add(0, x-m2x);
	f2.add(y, m2x-x);
	m2x = x;
      }
      ans -= y-2;
    } else {
      long long y = f2.sum(x);
      debug(y);
      debug(m1x);
      if (m1x > x) {
	f1.add(0, x-m1x);
	f1.add(y, m1x-x);
	m1x = x;
      }
      ans -= y-2;
    }
  }
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
