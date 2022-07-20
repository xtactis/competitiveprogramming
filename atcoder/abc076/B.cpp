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
	int n, k; scanf("%d%d", &n, &k);
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		if (ans*2 < ans+k) ans<<=1;
		else ans += k;
	}
	printf("%d", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
