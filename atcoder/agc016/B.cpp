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
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  if (a[n-1]-1 > a[0]) {
    puts("No");
    return;
  }
  int lo = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == a[0]) ++lo;
    else break;
  }
  int hi = n-lo;
  int x = a[0]-lo+1;
  if (hi) {
    if (1 <= x && x <= hi/2) puts("Yes");
    else puts("No");
  } else {
    if (x == 0 || n/2 >= a[0]) puts("Yes");
    else puts("No");
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
