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

const int N = 1e5+234;

int ar[N], br[N];

void solve() {
	int a, b, m; scanf("%d%d%d", &a, &b, &m);
	int mina = 2e9, minb = 2e9;
	for (int i = 0; i < a; ++i) {
		scanf("%d", ar+i);
		mina = min(mina, ar[i]);
	}
	for (int i = 0; i < b; ++i) {
		scanf("%d", br+i);
		minb = min(minb, br[i]);
	}
	int ans = mina+minb;
	for (int i = 0; i < m; ++i) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		--x; --y;
		ans = min(ans, ar[x]+br[y]-c);
	}
	printf("%d", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
