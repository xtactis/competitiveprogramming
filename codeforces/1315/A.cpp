#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, x, y; scanf("%d %d %d %d", &a, &b, &x, &y);
	int ans = max({a*y, x*b, (a-x-1)*b, a*(b-y-1)});
	printf("%d\n", ans);
}

int main() {
	int t = 1; scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
