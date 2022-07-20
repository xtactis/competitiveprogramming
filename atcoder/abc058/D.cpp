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

const int mod = 1e9+7;
const int N = 1e5+345;

int x[N], y[N];

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", x+i);
	for (int i = 0; i < m; ++i) scanf("%d", y+i);
	long long xs = 0;
	for (long long i = 0; i < n; ++i) {
		(xs += x[i] * (2*i - n + 1) % mod) %= mod;
	}
	debug(xs);
	long long ys = 0;
	for (long long i = 0; i < m; ++i) {
		(ys += y[i] * (2*i - m + 1) % mod) %= mod;
	}
	printf("%lld", xs*ys%mod);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
