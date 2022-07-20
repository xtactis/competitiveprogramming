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

pair<int, int> a[N];

bool solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  if (n == 1) {
    return true;
  }
  int t = -1, h = -1;
  while (true) {
    sort(a, a+n, greater<pair<int, int>>());
    if (a[0].second == h) {
      if (a[1].first == 0) return false;
      --a[1].first;
      t = a[1].second;
    } else {
      if (a[0].first == 0) return false;
      --a[0].first;
      t = a[0].second;
    }
    sort(a, a+n, greater<pair<int, int>>());
    if (a[0].second == t) {
      if (a[1].first == 0) return true;
      --a[1].first;
      h = a[1].second;
    } else {
      if (a[0].first == 0) return true;
      h = a[0].second;
      --a[0].first;
    }
  }
}

int main() {
  init();
  int t = 1; scanf("%d", &t);
  while (t--) {
    puts(solve()?"T":"HL");
  }
  return 0;
}
