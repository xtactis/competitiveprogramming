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

const int N = 1e5+34;

pair<int, int> a[N];

void solve() {
	int n, h; scanf("%d%d", &n, &h);
	int m = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].second, &a[i].first);
		m = max(m, a[i].second);
	}
	sort(a, a+n, greater<pair<int, int>>());
	long long tot = 0;
	int ans = 2e9;
	for (int i = 0; i <= n; ++i) {
		int x = max(0LL, h-tot);
		ans = min(ans, i+(x+m-1)/m);
		if (i == n) break;
		tot += a[i].first;
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
