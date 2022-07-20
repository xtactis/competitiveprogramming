#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; scanf("%d", &n);
	int prev = -1, cur = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		if (a > prev) ++cur;
		else cur = 1;
		prev = a;
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
