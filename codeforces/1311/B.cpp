#include <bits/stdc++.h>
using namespace std;

int a[123], p[123], b[123];
bool block[123];

void solve() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		b[i] = a[i];
		block[i] = true;
	}
	sort(b, b+n);
	for (int i = 0; i < m; ++i) {
		scanf("%d", p+i);
		block[p[i]-1] = false;
		//block[p[i]] = false;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) continue;
		int j = i-1;
		for (; j >= 0; --j) {
			if (block[j]) break;
		}
		for (++j; j < n; ++j) {
			if (b[j] == a[i]) break;
			if (block[j]) {
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}

int main() {
	int t = 1; scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
