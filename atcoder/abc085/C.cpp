#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void solve() {
	int n, y; scanf("%d%d", &n, &y);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n-i; ++j) {
			int x = i*10000+j*5000+(n-i-j)*1000;
			if (x == y) {
				printf("%d %d %d", i, j, n-i-j);
				return;
			}
		}
	}
	printf("-1 -1 -1");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
