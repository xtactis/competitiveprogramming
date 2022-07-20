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

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	int L = 1, R = n;
	for (int i = 0; i < m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		L = max(L, l);
		R = min(R, r);
	}
	printf("%d", max(R-L+1, 0));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
