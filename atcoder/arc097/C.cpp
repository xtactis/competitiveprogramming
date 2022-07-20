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
  string s; int k; cin >> s >> k;
  set<string> ss;
  vector<string> vs; 
  for (int i = 0; i < (int)s.size(); ++i) {
    vs.emplace_back();
    for (string &e: vs) {
      if (e.size() > k) continue;
      e += s[i];
      ss.insert(e);
    }
  }
  for (const string &s: ss) {
    if (--k) continue;
    cout << s;
    break;
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


