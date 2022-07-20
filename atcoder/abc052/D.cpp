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

int x[123434];

void solve() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
		scanf("%d", x+i);
	}
	long long ans = 0;
	for (int i = 0; i < n-1; ++i) {
		ans += min((long long)(x[i+1]-x[i])*a, (long long)b);
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
