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

long long dp[100];

long long lucas(int n) {
	if (n == 1) return 1;
	if (n == 0) return 2;
	if (dp[n]) return dp[n];
	return dp[n] = lucas(n-1)+lucas(n-2);
}

void solve() {
	int n; scanf("%d", &n);
	//printf("%lld", lucas(n));
	long long a = 2, b = 1;
	for (int i = 2; i <= n; ++i) {
		a += b;
		swap(a, b);
	}
	printf("%lld", b);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
