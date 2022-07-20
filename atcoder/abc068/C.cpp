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

const int N = 2e5+23;

vector<int> g[N];
int n, m; 

bool bio[N];
bool dfs(int u, int d) {
	bio[u] = true;
	bool ret = u == n-1;
	if (d-1 < 0) return ret;
	for (int v: g[u]) {
		if (bio[v]) continue;
		ret |= dfs(v, d-1);
	}
	return ret;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	if (!dfs(0, 2)) printf("IM");
	puts("POSSIBLE");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
