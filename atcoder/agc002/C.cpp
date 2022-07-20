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

int a[N];

void solve() {
  int n, l; scanf("%d%d", &n, &l);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  vector<int> v;
  for (int i = 0; i < n-1; ++i) {
    if (a[i]+a[i+1] < l) continue;
    v.push_back(i);
    for (int j = i-1; j >= 0; --j) v.push_back(j);
    for (int j = i+1; j < n-1; ++j) v.push_back(j);
    reverse(v.begin(), v.end());
    puts("Possible");
    for (int e: v) printf("%d\n", e+1);
    return;
  }
  puts("Impossible");
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
