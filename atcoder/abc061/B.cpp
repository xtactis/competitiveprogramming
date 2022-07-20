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

const int N = 56;

int c[N];

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		++c[--u]; ++c[--v];
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", c[i]);
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
