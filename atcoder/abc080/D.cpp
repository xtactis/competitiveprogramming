#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int C = 35;
const int T = 1e5+345;

bool ch[C][T];

void solve() {
	int n, c; scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i) {
		int s, t, c; scanf("%d%d%d", &s, &t, &c);
		--c;
		for (int j = s; j <= t; ++j) ch[c][j] = 1;
	}
	int ans = 0;
	for (int i = 1; i < T; ++i) {
		int cur = 0;
		for (int j = 0; j < c; ++j) {
			cur += ch[j][i];
		}
		ans = max(ans, cur);
	}
	printf("%d", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
