#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

const int N = 2e5+234;
const int mod = 998244353;

long long factorial[N+1];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	factorial[0] = 1;
	for (int i = 1; i <= N; i++) {
		factorial[i] = factorial[i - 1] * i % mod;
	}
}

long long binpow(long long b, long long e) {
	if (!e) return 1;
	if (e&1) return b*binpow(b, e-1)%mod;
	return binpow(b*b%mod, e/2);
}

long long binomial_coefficient(int n, int k) {
    return factorial[n] * binpow(factorial[k], mod-2) % mod * binpow(factorial[n - k], mod-2) % mod;
}

pair<long long, long long> x[N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		x[i] = make_pair(a, b);
	}
	sort(x, x+n);
	long long ans = 1;
	int cur = 1;
	for (int i = 0; i < n-1; ++i) {
		if (x[i].first + x[i].second >= x[i+1].first) ++cur;
		else {
			(ans *= cur+1) %= mod;
			cur = 1;
		}
	}
	(ans *= cur+1) %= mod;
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
