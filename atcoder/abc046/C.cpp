#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int n; scanf("%d", &n);
	long long T, A; scanf("%lld%lld", &T, &A);
	for (int i = 1; i < n; ++i) {
		long long t, a; scanf("%lld%lld", &t, &a);
		long long lo = 0, hi = 1e18+1;
		while (lo+1 < hi) {
			long long mid = lo+(hi-lo)/2;
			long long tm = t*mid, am = a*mid;
			if ((tm >= T && am >= A) || (tm/t != mid || am/a != mid)) hi = mid;
			else lo = mid;
		}
		T = t*hi; A = a*hi;
	}
	printf("%lld", T+A);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
