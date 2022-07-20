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

int a[123434];

void solve() {
	int n, x; scanf("%d %d", &n, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	long long ans = 0;
	for (int i = 0; i < n-1; ++i) {
		if (a[i]+a[i+1] > x) {
			int t = max(0, min(a[i+1], a[i]+a[i+1]-x));
			ans += t;
			a[i+1] -= t;
			t = max(0, min(a[i], a[i]+a[i+1]-x));
			ans += t;
			a[i] -= t;
		}
	}
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
