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

const int N = 123;

int a[N], l[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    scanf("%d", l+i);
    if (l[i] == 0) v.emplace_back(a[i]);
  }
  sort(v.begin(), v.end(), greater<int>());
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (l[i] == 0) {
      printf("%d ", v[j++]);
    } else {
      printf("%d ", a[i]);
    }
  }
  puts("");
}

int main() {
  init();
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
