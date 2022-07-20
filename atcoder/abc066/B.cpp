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

void solve() {
	string s; cin >> s;
	while (s.size()) {
		s.pop_back(); s.pop_back();
		int n = s.size()/2;
		bool f = true;
		for (int i = 0; f && i < n; ++i) {
			if (s[i] != s[i+n]) f = false;
		}
		if (f) {
			cout << s.size();
			return;
		}
	}
	cout << 0;
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
