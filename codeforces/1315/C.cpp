#include <bits/stdc++.h>
using namespace std;

const int N = 234;

int b[N], h[N], a[N];

int solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i <= 2*n; ++i) h[i] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", b+i);
		++h[b[i]];
	}
	for (int i = 0; i < n; ++i) {
		a[2*i] = b[i];
		bool f = false;
		for (int j = b[i]; j <= 2*n; ++j) {
			if (h[j] == 1) continue;
			a[2*i+1] = j;
			++h[j];
			f = true;
			break;
		}
		if (!f) return !puts("-1");
	}
	for (int i = 0; i < 2*n; ++i) {
		printf("%d ", a[i]);
	}
	return !puts("");
}

int main() {
	int t = 1; scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
