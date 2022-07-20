#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int n; scanf("%d", &n);
	int h[10] = {};
	for (int t, i = 0; i < n; ++i, ++h[min(t/400, 8)]) scanf("%d", &t);
	for (int i = 0; i < 8; ++i) h[9] += !!h[i];
	printf("%d %d", max(h[9], (int)!!h[8]), h[9]+h[8]);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
