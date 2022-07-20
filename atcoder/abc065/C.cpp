#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

const int N = 1e5+123;
const int mod = 1e9+7;

int fact[N];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = ((long long)fact[i-1]*i)%mod;
	}
}

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	if (n < m) swap(n, m);
	if (n-m >= 2) {
		printf("0");
		return;
	}
	if (n-m == 1) {
		printf("%lld", (long long)fact[n]*fact[m]%mod);
	} else {
		printf("%lld", (long long)fact[n]*fact[m]*2%mod);
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
