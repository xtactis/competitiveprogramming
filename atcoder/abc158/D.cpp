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
	string s; cin >> s;
	int q; cin >> q;
	bool oppo = false;
	string z, y; // y beg, z end
	while (q--) {
		int t, f; cin >> t;
		char c;
		if (t == 1) {
			oppo = !oppo;
		} else {
			cin >> f >> c;
			if (f == 1) {
				if (!oppo) y.push_back(c);
				else z.push_back(c);
			} else {
				if (!oppo) z.push_back(c);
				else y.push_back(c);
			}
		}
	}
	if (!oppo) {
		reverse(y.begin(), y.end());
		cout << y << s << z;
	} else {
		reverse(z.begin(), z.end());
		reverse(s.begin(), s.end());
		cout << z << s << y;
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
