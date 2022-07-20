#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;

int h[N];

void solve() {
	int n; scanf("%d", &n);
	int ans = 0, cur = 0;
	for (int i = 0; i < 2*n; ++i) {
		int x; scanf("%d", &x);
		++h[x];
		if (h[x] % 2 == 0) --cur;
		else ++cur;
		ans = max(ans, cur);
	}
	printf("%d", ans);
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
