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

const int N = 12343;

pair<int, int> p[N];
int n, w;

map<pair<int, long long>, long long> dp;

long long rek(int i, long long s) {
	if (i >= n) return 0;
	const auto pp = make_pair(i, s);
	if (dp.find(pp) != dp.end()) return dp[pp];
	if (p[i].first+s > w) return dp[pp] = rek(i+1, s);
	return dp[pp] = max(rek(i+1, s), rek(i+1, s+p[i].first)+p[i].second);
}

void solve() {
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; ++i) {
		int w, v; scanf("%d%d", &w, &v);
		p[i] = make_pair(w, v);
	}
	printf("%lld", rek(0, 0));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
