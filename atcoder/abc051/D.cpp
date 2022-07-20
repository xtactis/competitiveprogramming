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

const int N = 1e2+34;
const int M = 1e3+34;
const int inf = 2e9;

int a[M], b[M], c[M];
int d[N][N];

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", a+i, b+i, c+i);
		--a[i]; --b[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = inf;
		}
	}
	for (int i = 0; i < m; ++i) {
		d[a[i]][b[i]] = min(d[a[i]][b[i]], c[i]);
		d[b[i]][a[i]] = min(d[b[i]][a[i]], c[i]);
	}
	for (int k = 0; k < n; ++k) {
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n; ++i) {
				if (d[i][k] < inf && d[k][j] < inf) {
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
	}
	int ans = m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (d[j][b[i]] == d[a[i]][j]+c[i]) {
				--ans; break;
			}
		}
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
