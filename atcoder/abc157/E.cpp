#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

const int N = 5e5+23;
const int sqN = 800;

int n, q;
string s;
int a[710][30];


void solve() {
  cin >> n >> s >> q;
  for (int i = 0; i < n; ++i) {
    ++a[i/sqN][s[i]-'a'];
  }
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      --pos;
      c -= 'a';
      --a[pos/sqN][s[pos]-'a'];
      ++a[pos/sqN][c];
      s[pos] = c+'a';
    } else {
      int l, r; cin >> l >> r;
      --l; --r;
      int ans = 0;
      int h[30] = {0};
      for (int i = l; i <= r;) {
	if (i % sqN == 0 && i+sqN-1 <= r) {
	  for (int j = 0; j < 30; ++j) {
	    h[j] += a[i/sqN][j];
	  }
	  i += sqN;
	} else {
	  ++h[s[i]-'a'];
	  ++i;
	}
      }
      for (int i = 0; i < 30; ++i) if (h[i]) ++ans;
      printf("%d\n", ans);
    }
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
