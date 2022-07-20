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

const int N = 54;
int a[N];

void solve() {
	int n; scanf("%d", &n);
	int m = 0, M = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		if (a[m] > a[i]) m = i;
		if (a[M] < a[i]) M = i;
	}
	vector<pair<int, int>> vp;
	if (abs(a[M]) > abs(a[m])) {
		for (int i = 0; i < n; ++i) {
			if (a[i] >= 0) continue;
			a[i] += a[M];
			vp.emplace_back(M+1, i+1);
		}
		for (int i = 1; i < n; ++i) {
			vp.emplace_back(i, i+1);
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (a[i] <= 0) continue;
			a[i] += a[m];
			vp.emplace_back(m+1, i+1);
		}
		for (int i = n; i >= 2; --i) {
			vp.emplace_back(i, i-1);
		}
	}
	printf("%d\n", (int)vp.size());
	for (const auto &e: vp) {
		printf("%d %d\n", e.first, e.second);
	}
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
