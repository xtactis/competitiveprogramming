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

char s[123][123];

void solve() {
	int h, w; scanf("%d%d", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf(" %c", &s[i][j]);
		}
	}
	for (int i = 1; i <= 2*h; ++i) {
		for (int j = 0; j < w; ++j) {
			putchar(s[(i+1)/2-1][j]);
		}
		if (i < 2*h) puts("");
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
