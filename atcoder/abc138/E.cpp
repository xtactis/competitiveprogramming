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

vector<int> pos[30];

void solve() {
  string s, t; cin >> s >> t;
  for (int i = 0; i < s.size(); ++i) {
    pos[s[i]-'a'].push_back(i);
  }
  long long ans = 0, reps = 0, cur = -1;
  for (char c: t) {
    int d = c-'a';
    if (pos[d].empty()) {
      printf("-1");
      return;
    }
    auto spos = upper_bound(pos[d].begin(), pos[d].end(), cur);
    if (spos == pos[d].end()) {
      ++reps;
      cur = *pos[d].begin();
    } else {
      cur = *spos;
    }
    ans = reps*s.size() + cur;
  }
  printf("%lld", ans+1);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
