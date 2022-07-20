#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

const int N = 1e2+23;

int a[N];

void solve() {
	int n; scanf("%d", &n);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		s += a[i];
	}
	int ans = s%10?s:0;
	for (int i = 0; i < n; ++i) {
		int x = s-a[i];
		if (x%10==0) x = 0;
		ans = max(ans, x);
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
