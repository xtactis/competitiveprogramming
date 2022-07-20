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

int a[12][1234];

int reksum(int i, int j, int k, int l) {
	int x = a[k][l];
	if (i) x -= a[i-1][l];
	if (j) x -= a[k][j-1];
	if (i && j) x += a[i-1][j-1];
	return x;
}

void solve() {
	int h, w, K; scanf("%d%d%d", &h, &w, &K);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char c; scanf(" %c", &c);
			a[i][j] = c-'0';
			if (i) a[i][j] += a[i-1][j];
			if (j) a[i][j] += a[i][j-1];
			if (i && j) a[i][j] -= a[i-1][j-1];
		}
	}
	int ans = h+w-2;
	for (int i = 0; i < 1<<(h-1); ++i) {
		int cur = __builtin_popcount(i);
		int prevj = 0;
		bool g = false;
		for (int j = 0; j < w; ++j) {
			bool f = false;
			int prevk = 0;
			for (int k = 0; k < h-1; ++k) {
				if ((i&(1 << k)) == 0) continue;
				if (reksum(prevk, prevj, k, j) > K) f = true;
				if (f && reksum(prevk, prevj, k, j-1) > K) g = true;
				prevk = k+1;
			}
			if (reksum(prevk, prevj, h-1, j) > K || f) {
				if (reksum(prevk, prevj, h-1, j-1) > K) g = true;
				prevj = j;
				++cur;
			}
		}
		if (!g) ans = min(ans, cur);
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
