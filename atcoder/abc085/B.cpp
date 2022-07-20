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

int h[123];

void solve() {
	int n; scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		if (++h[x] == 1) ++ans;
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
