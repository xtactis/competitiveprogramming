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

const int N = 1e5+23;

int a[N];

void solve() {
  string s; cin >> s;
  vector<int> l, r;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'R') r.push_back(i);
    else l.push_back(i);
  }
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'R') {
      int j = lower_bound(l.begin(), l.end(), i)-l.begin();
      if ((l[j]-i)%2) {
	++a[l[j]-1];
      } else {
	++a[l[j]];
      }
    } else {
      int j = lower_bound(r.begin(), r.end(), i)-r.begin()-1;
      if ((i-r[j])%2) {
	++a[r[j]+1];
      } else {
	++a[r[j]];
      }
    }
  }
  for (int i = 0; i < (int)s.size(); ++i) cout << a[i] << ' ';
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
