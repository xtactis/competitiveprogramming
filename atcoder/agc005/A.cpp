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

const int N = 2e5+23;

int p[N];

void solve() {
  string s, q; cin >> q;
  for (bool change = true; change && q.size();) {
    change = false;
    s = q;
    debug(s);
    int ts = 0, ss = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'S') {
	if (ts) {
	  int a = min(ts, ss);
	  p[i-ts-a] = i-ts+a;
	  change = true;
	  ts = 0;
	  ss = 0;
	}
	++ss;
      } else {
	if (!ss) continue;
	++ts;
      }
    }
    if (ts) {
      int a = min(ts, ss);
      p[s.size()-ts-a] = s.size()-ts+a;
      change = true;
    }
    if (!change) break;
    q = "";
    for (int i = 0; i < s.size(); ++i) {
      while (p[i]) {
	int &prev = p[i];
	i = p[i];
	prev = 0;
      }
      if (i >= s.size()) break;
      q += s[i];
    }
  }
  cout << q.size();
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
