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
	int n, m, a, b, c;
	string s, p, q;
	cin >> s >> p >> q;
	if (s.back() == p[0] && p.back() == q[0]) {
		cout << "YES";
	} else {
		cout << "NO";
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
