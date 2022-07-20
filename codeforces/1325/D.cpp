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

int solve() {
  long long u, v; scanf("%lld %lld", &u, &v);
  if (!u && !v) return !printf("0");
  if (u == v) return !printf("1\n%lld", u);
  if (u > v || (u%2 != v%2)) return !printf("-1");
  vector<long long> a, b;
  for (long long i = 1; i <= u; i <<= 1) {
    if ((u&i)==0) continue;
    a.push_back(i);
  }
  v -= u;
  for (long long i = 2; i <= v; i <<= 1) {
    if ((v&i)==0) continue;
    b.push_back(i/2);
    b.push_back(i/2);
  }
  vector<bool> bio(a.size());
  for (long long &e: b) {
    for (int i = 0; i < (int)a.size(); ++i) {
      if (e&a[i]) continue;
      if (bio[i]) continue;
      e |= a[i];
      bio[i] = 1;
    }
  }
  long long s = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (bio[i]) continue;
    s += a[i];
  }
  bio.clear();
  bio.assign(b.size(), 0);
  for (int i = 0; i < (int)b.size(); ++i) {
    if (!b[i]) continue;
    for (int j = 0; j < (int)b.size(); ++j) {
      if (!b[j]) continue;
      if (b[i]&b[j]) continue;
      b[i] += b[j];
      b[j] = 0;
    }
  }
  a.clear();
  for (int i = 0; i < (int)b.size(); ++i) {
    if (!b[i]) continue;
    a.push_back(b[i]);
  }
  if (s) a.push_back(s);
  printf("%d\n", a.size());
  for (long long e: a) printf("%lld ", e);
  return 0;
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
