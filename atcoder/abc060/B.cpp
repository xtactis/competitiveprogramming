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
	int a, b, c; cin >> a >> b >> c;
	for (int i = 1; i < 10000; ++i) {
		if (i*a%b == c) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
