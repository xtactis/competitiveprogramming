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

const int N = 1e5+23;
long long v[2][N];
int S[2];

long long closest(long long x, int w, int depth) {
  if (!depth) return 0;
  long long *s = lower_bound(v[w], v[w]+S[w], x);
  long long ret = 1e15;
  if (s-v[w] < S[w]) {
    ret = *s-x + closest(*s, !w, depth-1);
  }
  if (s-v[w] > 0) {
    ret = min(ret, abs(*--s-x)+closest(*s, !w, depth-1));
  }
  return ret;
}

void solve() {
  int q; scanf("%d%d%d", S, S+1, &q);
  for (int i = 0; i < S[0]; ++i) {
    scanf("%lld", v[0]+i);
  }
  for (int i = 0; i < S[1]; ++i) {
    scanf("%lld", v[1]+i);
  }
  for (int i = 0; i < q; ++i) {
    long long x; scanf("%lld", &x);
    printf("%lld\n", min(closest(x, 0, 2), closest(x, 1, 2)));
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
