#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, k; cin >> a >> b >> c >> k;
  int ans = min(a, k)-min(c, max(0, k-a-b));
  cout << ans;
  return 0;
}
