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

const int N = 234;
const long long INF = 1e17;

int R[10];
long long d[N][N];

void solve() {
	int n, m, r; scanf("%d%d%d", &n, &m, &r);
	for (int i = 0; i < n; ++i) {
		d[i][i] = 0;
		for (int j = i+1; j < n; ++j) {
			d[j][i] = d[i][j] = INF;
		}
	}
	for (int i = 0; i < r; --R[i++]) scanf("%d", R+i);
	for (int i = 0; i < m; ++i) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		d[b][a] = d[a][b] = c;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	long long ans = INF;
	sort(R, R+r);
	do {
		long long cur = 0;
		for (int i = 1; i < r; ++i) {
			cur += d[R[i-1]][R[i]];
		}
		ans = min(ans, cur);
	} while (next_permutation(R, R+r));
	printf("%lld", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
