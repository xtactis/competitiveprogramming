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

string s[N];

void solve() {
  int n, a, b, c; cin >> n >> a >> b >> c;
  string ans;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    if (s[i] == "AB") {
      if (a < 1) {
	++a, --b;
	ans += 'A';
      }
      else {
	++b, --a;
	ans += 'B';
      }
      --c;
    } else if (s[i] == "AC") {
      if (a < 1) {
	++a, --c;
	ans += 'A';
      } else {
	++c, --a;
	ans += 'C';
      }
      --b;
    } else {
      if (b < 1) {
	++b, --c;
	ans += 'B';
      } else {
	++c, --b;
	ans += 'C';
      }
      --a;
    }
    if (a < 0 || b < 0 || c < 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (char c: ans) cout << c << '\n';
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
