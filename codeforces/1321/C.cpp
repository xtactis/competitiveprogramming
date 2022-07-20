#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

const int inf = 2e9;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	for(;;) {
		char mr = 0;
		for (int i = 0; i < n; ++i) {
			if ((i > 0 && s[i] == s[i-1]+1) || (i < n-1 && s[i] == s[i+1]+1)) {
				mr = max(mr, s[i]);
			}
		}
		if (mr == 0) break;
		++ans;
		for (int i = 0; i < n; ++i) {
			if (s[i] == mr && ((i > 0 && s[i] == s[i-1]+1) || (i < n-1 && s[i] == s[i+1]+1))) {
				s = s.substr(0, i)+s.substr(i+1, n);
				debug(s);
				--n;
				break;
			}
		}
	}
	cout << ans;
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
