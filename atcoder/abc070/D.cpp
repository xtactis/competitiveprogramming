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

const int N = 1e5+23;

vector<pair<int, int>> g[N];

long long bio[N];
void dfs(int u, long long d) {
	bio[u] = d;
	for (const auto &e: g[u]) {
		if (bio[e.first]) continue;
		dfs(e.first, d+e.second);
	}
}

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		g[--a].emplace_back(--b, c);
		g[b].emplace_back(a, c);
	}
	int q, k; scanf("%d%d", &q, &k);
	dfs(--k, 1);
	while (q--) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%lld\n", bio[--a]+bio[--b]-2);
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
