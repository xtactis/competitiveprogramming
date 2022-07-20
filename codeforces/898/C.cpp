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

map<string, set<string>> pb;

bool suf(const string &s, const string &q) {
  if (s.size() >= q.size()) return false;
  for (int i = 1; i <= (int)s.size(); ++i) {
    if (q[q.size()-i] != s[s.size()-i]) return false;
  }
  return true;
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    int c; cin >> s >> c;
    for (int j = 0; j < c; ++j) {
      string ns; cin >> ns;
      pb[s].insert(ns);
    }
  }
  cout << pb.size() << '\n';
  for (const auto &p: pb) {
    cout << p.first << ' ';
    vector<string> ans;
    for (const auto &s: p.second) {
      bool f = true;
      for (const auto &q: p.second) {
	if (s == q) continue;
	if (suf(s, q)) {
	  f = false;
	  break;
	}
      }
      if (f) ans.push_back(s);
    }
    cout << ans.size() << ' ';
    for (const auto &s: ans) cout << s << ' ';
    cout << '\n';
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
