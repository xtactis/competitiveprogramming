#include <bits/stdc++.h>
using namespace std;

void init() {

}

void solve() {
	int n, k, x, y; scanf("%d%d%d%d", &n, &k, &x, &y);
	printf("%lld", (long long)min(k, n)*x + max(n-k, 0)*y);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
