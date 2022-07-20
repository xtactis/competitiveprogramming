#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int N = 123;
const long long inf = 1e17;

int f[N][5][2];
int p[N][10];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d%d", f[i][j], f[i][j]+1);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 11; ++j) {
			scanf("%d", p[i]+j);
		}
	}
	int i[5];
	long long ans = -inf;
	for (i[0] = 0; i[0] < 4; ++i[0]) {
		for (i[1] = 0; i[1] < 4; ++i[1]) {
			for (i[2] = 0; i[2] < 4; ++i[2]) {
				for (i[3] = 0; i[3] < 4; ++i[3]) {
					for (i[4] = 0; i[4] < 4; ++i[4]) {
						if (!(i[0] || i[1] || i[2] || i[3] || i[4])) continue;
						int c[N] = {};
						long long cur = 0;
						for (int j = 0; j < n; ++j) {
							for (int k = 0; k < 5; ++k) {
								c[j] += f[j][k][0] && (i[k]&1);
								c[j] += f[j][k][1] && (i[k]&2);
							}
							cur += p[j][c[j]];
						}
						ans = max(cur, ans);
					}
				}
			}
		}
	}
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
