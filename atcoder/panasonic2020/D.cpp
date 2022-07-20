#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

vector<string> v;

void gen(const string &s, char c, int n) {
  if (n == 0) {
    v.push_back(s);
    return;
  }
  for (char x = 'a'; x <= c; ++x) {
    gen(s+x, max((char)(x+1), c), n-1);
  }
}

void solve() {
  int n; cin >> n;
  gen("a", 'b', n-1);
  sort(v.begin(), v.end());
  for (const string &s: v) {
    cout << s << endl;
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
