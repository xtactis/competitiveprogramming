#include <bits/stdc++.h>
using namespace std;

int d[12];

bool check(int x) {
	while (x > 0) {
		if (d[x%10]) return false;
		x /= 10;
	}
	return true;
}

void solve() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int t; scanf("%d", &t);
		d[t] = 1;
	}
	for (int i = n;; ++i) {
		if (check(i)) {
			printf("%d", i);
			return;
		}
	}
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
