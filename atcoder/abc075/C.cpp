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

vector<int> g[N];
int tin[N], low[N];
bool bio[N];
int timer, ans;

void dfs(int u, int p=-1) {
	bio[u] = true;
	tin[u] = low[u] = timer++;
	for (int v: g[u]) {
		if (v == p) continue;
		if (bio[v]) {
			low[u] = min(low[u], low[v]);
			continue;
		}
		dfs(v, u);
		low[u] = min(low[u], low[v]);
		if (low[v] > tin[u]) ++ans;
	}
}

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) tin[i] = low[i] = -1;
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	dfs(0);
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
