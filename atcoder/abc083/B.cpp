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

int count(int x) {
	if (!x) return 0;
	return x%10+count(x/10);
}

void solve() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		int c = count(i);
		if (a <= c && c <= b) ans += i;
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
