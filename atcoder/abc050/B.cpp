#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int t[1234];

void solve() {
	int n; scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", t+i);
		sum += t[i];
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int p, x; scanf("%d%d", &p, &x);
		printf("%lld\n", sum-t[p-1]+x);
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
