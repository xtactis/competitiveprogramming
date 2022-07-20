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

map<int, long long> m;

void solve() {
	int n;
	long long k; scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		m[a] += b;
	}
	long long c = 0;
	for (const auto &e: m) {
		c += e.second;
		if (c >= k) {
			printf("%d", e.first);
			break;
		}
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
