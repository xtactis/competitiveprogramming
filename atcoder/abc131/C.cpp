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

long long cnt(long long a, long long x, long long y) {
  long long g = __gcd(x, y);
  return a/x+a/y-a/(x*y/g);
}

void solve() {
  long long a, b, c, d; cin >> a >> b >> c >> d;
  cout << b-a-(cnt(b, c, d)-cnt(a-1, c, d))+1;
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
