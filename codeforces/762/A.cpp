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
	long long n, k; scanf("%lld%lld", &n, &k);
	set<long long> divisors;
	for (long long i = 1; i*i <= n; ++i) {
		long long x = 1;
		while ((n/x)%i==0) {
			x *= i;
			divisors.insert(x);
			divisors.insert(n/x);
			if (i == 1) break;
		}
	}
	if ((int)divisors.size() < k) {
		printf("-1"); return;
	}
	int c = 1;
	for (long long e: divisors) {
		if (c++ == k) {
			printf("%lld", e);
			break;
		}
	}
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
