#include <bits/stdc++.h>
#include <atcoder/lazysegtree>

using namespace std;
using namespace atcoder;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int mod = 998244353;
const int N = 2e5+23;

long long T[N];

struct S {
  long long x;
  int pos;
};

struct F {
  long long b;
};

S op(S a, S b) {
  return {(a.x*T[a.pos]%mod+b.x*T[b.pos]%mod)%mod, min(a.pos, b.pos)};
}

S e() {
  return {0, 0};
}

S mapping(F f, S x) {
  return x;
}

F comp(F f, F g) {
  return F{1};
}

F id() {
  return F{1};
}

void solve() {
  int n, q; scanf("%d%d", &n, &q);
  lazy_segtree<S, op, e, F, mapping, comp, id> seg(n);
  T[n-1] = 1;
  for (int i = n-2; i >= 0; --i) {
    T[i] = (T[i+1] * 10) % mod;
  }
  for (int i = 0; i < n; ++i) {
    seg.set(i, {1, i});
  }
  printf("%lld", seg.all_prod());
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
