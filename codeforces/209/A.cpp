#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

const int N = 1e6+23;
const int mod = 1e9+7;

int dp[N];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int n; scanf("%d", &n);
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i-1]+i+(i-i%2)/2;
	}
	for (int i = 1; i <= n; ++i) {
		debug(dp[i]);
	}
	printf("%d", dp[n]);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
