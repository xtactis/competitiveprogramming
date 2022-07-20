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

const int N = 100*100+23;

int a[N];
int m[123][123];

void solve() {
	int h, w, n; scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	int k = 0, c = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; i%2 && j < w; ++j) {
			m[i][j] = k+1;
			++c;
			if (c == a[k]) {
				++k; c = 0;
			}
		}
		for (int j = w-1; i%2 == 0 && j >= 0; --j) {
			m[i][j] = k+1;
			++c;
			if (c == a[k]) {
				++k; c = 0;
			}
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			printf("%d ", m[i][j]);
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
