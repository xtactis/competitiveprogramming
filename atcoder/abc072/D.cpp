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

const int N = 1e5+34;

int a[N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	int ans = 0;
	int bad = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == i+1) {
			++bad;
			continue;
		}
		if (!bad) continue;
		ans += (bad+1)/2;
		bad = 0;
	}
	if (bad) ans += (bad+1)/2;
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
