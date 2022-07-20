#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int R[123][123];

void fill(int l, int d, int r, int u) {
	if (l > r) swap(l, r);
	if (d > u) swap(d, u);
	for (int i = l; i < r; ++i) {
		for (int j = d; j < u; ++j) {
			R[i][j] = 1;
		}
	}
}

void solve() {
	int w, h; scanf("%d %d", &w, &h);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y, a; scanf("%d %d %d", &x, &y, &a);
		if (a == 1) {
			// x < xi
			fill(0, 0, x, h);
		} else if (a == 2) {
			// x > xi
			fill(x, 0, w, h);
		} else if (a == 3) {
			// y < yi
			fill(0, 0, w, y);
		} else {
			// y > yi
			fill(0, y, w, h);
		}
	}
	int ans = 0;
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			if (!R[i][j]) ++ans;
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
