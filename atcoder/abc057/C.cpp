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

int f(int a, int b) {
	int ret = 0;
	while (a) {
		a /= 10;
		++ret;
	}
	int cur = 0;
	while (b) {
		b /= 10;
		++cur;
	}
	return max(ret, cur);
}

void solve() {
	long long n; scanf("%lld", &n);
	vector<long long> v;
	for (long long i = 1; i*i <= n; ++i) {
		if (n%i == 0) v.push_back(i);
	}
	int ans = 2e9;
	for (long long x: v) {
		ans = min(ans, f(x, n/x));
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
