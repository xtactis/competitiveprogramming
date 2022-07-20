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

const int N = 123;

int a[2][N];

void solve() {
	int n; scanf("%d", &n);
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", a[j]+i);
			if (i) a[j][i] += a[j][i-1];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, a[0][i]+a[1][n-1]-(i?a[1][i-1]:0));
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
