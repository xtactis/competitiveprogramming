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

int a[10];
int h[] = {0,2,5,5,4,5,6,3,7,6};

int 

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int x, i = 0; i < m; ++i) {
    scanf("%d", &x);
    a[x] = 1;
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
