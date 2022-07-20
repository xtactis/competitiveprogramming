#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int k, s; scanf("%d%d", &k, &s);
	int ans = 0;
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (s-i-j <= k && s-i-j >= 0) ++ans;
		}
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
