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

const int N = 3e5+23;
int a[N];
int n, q;

void solve() {
  scanf("%d%d", &n, &q);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
  }
  a[n+1] = 0;
  for (int i = 1; i <= n; ++i) sum += max(0, a[i]-a[i+1]);
  printf("%lld\n", sum);
  const auto foo = [](int i) {return max(0, a[i]-a[i+1])+max(0, a[i-1]-a[i]);};
  while (q--) {
    int u, v; scanf("%d%d", &u, &v);
    int t = foo(u);
    if (u+1 != v) t += foo(v);
    else t += max(0, a[v]-a[v+1]);
    sum -= t;
    swap(a[u], a[v]);
    t = foo(u);
    if (u+1 != v) t += foo(v);
    else t += max(0, a[v]-a[v+1]);
    sum += t;
    printf("%lld\n", sum);
  }
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
