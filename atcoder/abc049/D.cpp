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

const int N = 2e5+234;

int bio[2][N];
vector<int> g[2][N];

void dfs(int u, int c, int b) {
	bio[b][u] = c;
	for (int v: g[b][u]) {
		if (bio[b][v]) continue;
		dfs(v, c, b);
	}
}

void solve() {
	int n, k, l; scanf("%d%d%d", &n, &k, &l);
	for (int i = 0; i < k; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[0][--u].push_back(--v);
		g[0][v].push_back(u);
	}
	for (int i = 0; i < l; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[1][--u].push_back(--v);
		g[1][v].push_back(u);
	}
	for (int b = 0; b < 2; ++b) {
		int c = 1;
		for (int i = 0; i < n; ++i) {
			if (bio[b][i]) continue;
			dfs(i, c++, b);
		}
	}
	map<pair<int, int>, int> m;
	for (int i = 0; i < n; ++i) {
		++m[make_pair(bio[0][i], bio[1][i])];
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", m[make_pair(bio[0][i], bio[1][i])]);
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
