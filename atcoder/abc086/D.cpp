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

const int N = 1e5+34;
const int K = 1e3+23;

int n, k;
long long m[4*K][4*K];

int rect(int i, int j, int I, int J) {
	int x = i&&j?m[i-1][j-1]:0,
		y = i?m[i-1][J]:0,
		z = j?m[I][j-1]:0;
	return m[I][J]-z-y+x;
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x, y; char c; scanf("%d%d %c", &x, &y, &c);
		if (c == 'W') x += k;
		x %= 2*k; y %= 2*k;
		m[x+2*k][y+2*k] = m[x][y+2*k] = m[x+2*k][y] = ++m[x][y];
	}
	for (int i = 0; i < 4*k; ++i) {
		for (int j = 0; j < 4*k; ++j) {
			if (i) m[i][j] += m[i-1][j];
			if (j) m[i][j] += m[i][j-1];
			if (i && j) m[i][j] -= m[i-1][j-1];
		}
	}
	int ans = 0;
	for (int i = 0; i < 2*k; ++i) { // offset x
		for (int j = 0; j < 2*k; ++j) { // offset y
			ans = max(ans, rect(i, j, i+k-1, j+k-1) + rect(i+k, j+k, i+2*k-1, j+2*k-1));
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
