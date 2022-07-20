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

const int N = 54;

char a[N][N];

void incM(int y, int x) {
	if (a[y][x] == '#') return;
	++a[y][x];
}

void solve() {
	int h, w; scanf("%d%d", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char c; scanf(" %c", &c);
			if (c == '#') {
				a[i][j] = c;
				if (i) {
					if (j) incM(i-1, j-1);
					incM(i-1, j);
					if (j+1 < w) incM(i-1, j+1);
				}
				if (j) incM(i, j-1);
			} else {
				a[i][j] = '0';
				if (i) {
					if (a[i-1][j] == '#') ++a[i][j];
					if (j && a[i-1][j-1] == '#') ++a[i][j];
					if (j+1 < w && a[i-1][j+1] == '#') ++a[i][j];
				}
				if (j && a[i][j-1] == '#') ++a[i][j];
			}
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			putchar(a[i][j]);
		}
		puts("");
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
