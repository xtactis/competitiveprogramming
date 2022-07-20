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

int H[45][20];
vector<pair<int, int>> v;

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    long long num = 0;
    int t = 0, f = 0;
    bool start = false;
    for (int j = 0; j < (int)s.size(); ++j) {
      if (s[j] == '.') {
	start = true;
	continue;
      }
      num *= 10;
      num += s[j]-'0';
      if (start) t = --f;
    }
    while (num%2==0) {
      ++t;
      num /= 2;
    }
    while (num%5==0) {
      ++f;
      num /= 5;
    }
    v.emplace_back(f, t);
    debug(f);
    debug(t);
  }
  long long ans = 0;
  sort(v.begin(), v.end());
  for (int i = 0; i < (int)v.size(); ++i) {
    const auto &e = v[i];
    for (int f = -e.first; f < 20; ++f) {
      ans += upper_bound(v.begin()+i+1, v.end(), make_pair(f+1, -45))-lower_bound(v.begin()+i+1, v.end(), make_pair(f, -e.second));
    }
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
