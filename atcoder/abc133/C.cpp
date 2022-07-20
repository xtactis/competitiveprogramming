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

void solve() {
	int l, r; scanf("%d%d", &l, &r);
	if (r-l >= 2019) {
		printf("0");
		return;
	}
	long long ans = 2020;
	for (long long i = l; i <= r; ++i) {
		for (int j = i+1; j <= r; ++j) {
			ans = min(ans, i*j%2019);
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
