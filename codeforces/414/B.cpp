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

const int N = 2e3+34;
const int mod = 1e9+7;

long long dp[N][N];

int n, k;

long long rek(int x, int k) {
	if (x > n) return 0;
	if (k <= 0) return 1;
	long long &ret = dp[x][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = x; i <= n; i+=x) {
		(ret += rek(i, k-1)) %= mod;
	}
	return ret;
}

void solve() {
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) dp[i][j] = -1;
	scanf("%d%d", &n, &k);
	printf("%lld", rek(1, k));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
