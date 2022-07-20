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

int c[10][10];

void solve() {
	int h, w; scanf("%d%d", &h, &w);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			scanf("%d", c[i]+j);
		}
	}
	for (int k = 0; k < 10; ++k) {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < h*w; ++i) {
		int a; scanf("%d", &a);
		if (a == -1) continue;
		ans += c[a][1];
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
