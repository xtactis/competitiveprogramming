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

const int N = 54;
const long long inf = 9e18;

pair<int, int> a[N];
int xs[N], ys[N];

void solve() {
	int z, n; scanf("%d%d", &n, &z);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
		xs[i] = a[i].first;
		ys[i] = a[i].second;
	}
	long long ans = inf;
	sort(xs, xs+n);
	sort(ys, ys+n);
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				for (int l = k+1; l < n; ++l) {
					int cur = 0;
					for (int m = 0; m < n && cur < z; ++m) {
						if (a[m].first >= xs[i] && a[m].first <= xs[j]
						 && a[m].second >= ys[k] && a[m].second <= ys[l]) ++cur;
					}
					if (cur >= z) {
						ans = min(ans, (long long)(xs[j]-xs[i])*(ys[l]-ys[k]));
					}
				}
			}
		}
	}
	printf("%lld", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
