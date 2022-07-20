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
	int h, w; cin >> h >> w;
	for (int i = 0; i < w+2; ++i) cout << '#';
	cout << '\n';
	for (int i = 0; i < h; ++i) {
		cout << '#';
		string s; cin >> s;
		cout << s << "#\n";
	}
	for (int i = 0; i < w+2; ++i) cout << '#';
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
