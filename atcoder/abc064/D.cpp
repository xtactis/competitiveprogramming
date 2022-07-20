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
	int n; cin >> n;
	string s; cin >> s;
	int pre = 0, post = 0;
	for (char c: s) {
		if (c == ')') --post;
		else ++post;
		if (post < 0) {
			++pre;
			post = 0;
		}
	}
	debug(pre); debug(post);
	for (int i = 0; i < pre; ++i) cout << '(';
	cout << s;
	for (int i = 0; i < post; ++i) cout << ')';
	
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
