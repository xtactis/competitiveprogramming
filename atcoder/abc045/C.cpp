#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

long long count(int mask, long long n) {
	long long ret = 0;
	long long cur = 0;
	while (n) {
		cur = cur*10+n%10;
		if (mask&1) {
			ret += cur;
			cur = 0;
		}
		n /= 10;
		mask >>= 1;
	}
	return ret+cur;
}

void solve() {
	long long n; scanf("%lld", &n);
	long long ans = 0;
	long long m = n, c = -1;
	long long newN = 0;
	while (m) {
		newN = newN*10+m%10;
		m /= 10;
		++c;
	}
	for (int i = 0; i < 1<<c; ++i) {
		ans += count(i, newN);
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
