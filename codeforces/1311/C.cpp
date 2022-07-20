#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int h[N][26];
int ans[26];

void solve() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < 26; ++i) {
		h[0][i] = 0;
		ans[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		char c; scanf(" %c", &c);
		for (int j = 0; i > 0 && j < 26; ++j) {
			h[i][j] = h[i-1][j];
		}
		++h[i][c-'a'];
		++ans[c-'a'];
	}
	for (int i = 0; i < m; ++i) {
		int p; scanf("%d", &p);
		for (int j = 0; j < 26; ++j) {
			ans[j] += h[p-1][j];
		}
	}
	for (int i = 0; i < 26; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
}

int main() {
	int t = 1; scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
