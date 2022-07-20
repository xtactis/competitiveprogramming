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

const int N = 512;
const int inf = 2e9;

int a[N], n, k;

void solve() {
  scanf("%d%d", &n, &k);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    s += a[i];
  }
  vector<int> divs;
  for (int i = 1; i*i <= s; ++i) {
    if (s%i) continue;
    divs.push_back(i);
    if (i*i == s) break;
    divs.push_back(s/i);
  }
  int ans = 1;
  for (int e: divs) {
    vector<int> r;
    for (int i = 0; i < n; ++i) {
      if (a[i]%e) r.push_back(a[i]%e);
    }
    if (!r.size()) {
      ans = max(ans, e);
      continue;
    }
    sort(r.begin(), r.end());
    for (int i = 1; i < (int)r.size(); ++i) {
      r[i] += r[i-1];
    }
    for (int i = 0; i < (int)r.size(); ++i) {
      int other = ((r.size()-i-1)*e-(r[r.size()-1]-r[i]));
      if (r[i]-other != 0 || r[i]+other > 2*k) continue;
      ans = max(ans, e);
      break;
    }
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
