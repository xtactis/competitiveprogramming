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
	int n, t; scanf("%d%d", &n, &t);
	long long ans = 0, last = -1;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		if (last == -1) {
			last = x;
			continue;
		}
		if (x-last > t) {
			ans += t;
		} else {
			ans += x-last;
		}
		last = x;
	}
	ans += t;
	printf("%lld", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
