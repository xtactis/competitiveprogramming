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
	int n, m; scanf("%d%d", &n, &m);
	vector<int> a;
	a.assign(n, 0);
	for (int i = 0; i < m; ++i) {
		int s, c; scanf("%d%d", &s, &c);
		if (n > 1 && s == 1 && c == 0) {
			puts("-1");
			return;
		}
		if (a[s-1] == 0 || a[s-1] == c) a[s-1] = c;
		else {
			puts("-1");
			return;
		}
	}
	if (n != 1 && a[0] == 0) a[0] = 1;
	for (int i = 0; i < n; ++i) {
		printf("%d", a[i]);
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
