#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int x = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'I') ++x;
		else if (s[i] == 'D') --x;
		ans = max(ans, x);
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
