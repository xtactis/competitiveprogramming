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

string s;

bool check(int l, int r) {
	for (int i = l; i <= (l+r)/2; ++i) {
		debug(s[i]);
		debug(s[r-i-1]);
		if (s[i] != s[r-i-1]) return false;
	}
	return true;
}

void solve() {
	cin >> s;
	const int n = s.size();
	if (check(0, n) && check(0, (n-1)/2) && check((n+3)/2-1, n)) cout << "Yes";
	else cout << "No";
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
