#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

const int N = 1e3+34;
const long long inf = 2e18;

long long d[N];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < N; ++i) d[i] = inf;
}

struct edge {
	int a, b, w;
};

edge g[3*N];
bool negs[N];

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &g[i].a, &g[i].b, &g[i].w);
		--g[i].a; --g[i].b;
		g[i].w *= -1;
	}
	d[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[g[j].a] < inf) {
				if (d[g[j].b] > d[g[j].a] + g[j].w) {
					d[g[j].b] = max(-inf, d[g[j].a]+g[j].w);
					if (i == n-1) negs[g[j].b] = true;
				}
				if (i == n-1 && negs[g[j].a]) negs[g[j].b] = true;
			}
		}
	}
	if (negs[n-1]) {
		puts("inf");
	} else {
		printf("%lld", -d[n-1]);
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
