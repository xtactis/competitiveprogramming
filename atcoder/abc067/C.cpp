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

const int N = 2e5+234;
const long long inf = 1e17;

long long a[N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", a+i);
		if (i == 0) continue;
		a[i] += a[i-1];
	}
	long long ans = inf;
	for (int i = 0; i < n-1; ++i) {
		ans = min(ans, abs(a[i]-(a[n-1]-a[i])));
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
