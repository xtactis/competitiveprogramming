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

const int N = 1e4+23;

int a[N], b[N];
long long totA = 0, totB = 0;

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  for (int i = 0; i < n; ++i) scanf("%d", b+i);
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      totB += a[i]-b[i];
    } else {
      if (a[i]%2 != b[i]%2) {
	++b[i];
	++totB;
      }
      totA += (b[i]-a[i])/2;
    }
    //printf("%d %d\n", totA, totB);
  }
  if (totA >= totB)  puts("Yes");
  else puts("No");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
