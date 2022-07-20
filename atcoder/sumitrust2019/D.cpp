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

vector<int> h[12];

void solve() {
  int n; string s; cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    h[s[i]-'0'].push_back(i);
  }
  set<string> ss;
  for (int i = 0; i < n-2; ++i) {
    for (char j = 0; j < 10; ++j) {
      int ij = upper_bound(h[j].begin(), h[j].end(), i)-h[j].begin();
      int cj = h[j].size() - ij;
      if (!cj) continue;
      for (char k = 0; k < 10; ++k) {
	int ik = upper_bound(h[k].begin(), h[k].end(), h[j][ij])-h[k].begin();
	int ck = h[k].size() - ik;
	if (!ck) continue;
	ss.insert(string({s[i], s[h[j][ij]], s[h[k][ik]]}));
      }
    }
  }
  printf("%d", ss.size());
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
