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
	int n; scanf("%d", &n);
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		long long t; scanf("%lld", &t);
		ans = max(t, ans)/__gcd(t, ans)*min(t, ans);
		//ans = __lcm(t, ans);
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
