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
vector<int> g[N];

int bio[N];
void dfs(int u, int d=1) {
	bio[u] = d;
	for (int v: g[u]) {
		if (bio[v]) {
			bio[v] = min(bio[v], d+1);
			continue;
		}
		dfs(v, d+1);
	}
}

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t; scanf("%d", &t);
		g[i].push_back(--t);
	}
	dfs(0);
	printf("%d", bio[1]-1);
}	

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
