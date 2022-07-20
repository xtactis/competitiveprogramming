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

vector<int> g[N];
int c[2][N];
int b;

void dfs(int u, int x, int d=1) {
	c[x][u] = d;
	for (int v: g[u]) {
		if (c[x][v]) continue;
		dfs(v, x, d+1);
	}
}

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	dfs(0, 0);
	dfs(n-1, 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (c[0][i] <= c[1][i]) ++ans;
	}
	debug(b);
	debug(ans);
	printf(ans>n-ans?"Fennec":"Snuke");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
