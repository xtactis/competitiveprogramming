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

void solve() {
  int n; scanf("%d", &n);
  vector<int> sq, nsq;
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    int s = round(sqrt(a));
    if (s*s == a) sq.push_back(a);
    else nsq.push_back(a);
  }
  long long ans = 0;
  if (sq.size() > nsq.size()) {
    sort(sq.begin(), sq.end(), greater<int>());
    for (int i = 0; i < (sq.size()-nsq.size())/2; ++i) {
      if (sq[i] == 0) {
	ans += 2;
      } else {
	++ans;
      }
    }
    printf("%lld", ans);
  } else if (sq.size() < nsq.size()) {
    vector<int> d;
    for (int x: nsq) {
      int s = floor(sqrt(x));
      d.push_back(min(abs(x-s*s), abs((s+1)*(s+1)-x)));
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < (nsq.size()-sq.size())/2; ++i) {
      ans += d[i];
    }
    printf("%lld", ans);
  } else {
    puts("0");
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
