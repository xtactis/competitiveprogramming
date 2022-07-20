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

const int N = 1e5+23;
const long long inf = 1e15;

pair<int, int> xs[N];
pair<int, int> ys[N];
vector<pair<int, int>> g[N];
vector<pair<long long, int>> min_e(N, {inf, -1});
set<pair<long long, int>> q;

bool bio[N];
long long prim(int n) {
	long long total = 0;
	min_e[0].first = 0;
	q.insert({0, 0});
	for (int i = 0; i < n; ++i) {
		assert(!q.empty());
		int v = q.begin()->second;
		bio[v] = true;
		total += q.begin()->first;
		q.erase(q.begin());
		for (const auto &e: g[v]) {
			if (bio[e.first] || e.second >= min_e[e.first].first) continue;
			q.erase({min_e[e.first].first, e.first});
			min_e[e.first] = {e.second, v};
			q.insert({e.second, e.first});
		}
	}
	return total;
}

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &xs[i].first, &ys[i].first);
		xs[i].second = ys[i].second = i;
	}
	sort(xs, xs+n);
	sort(ys, ys+n);
	for (int i = 1; i < n; ++i) {
		g[xs[i].second].emplace_back(xs[i-1].second, xs[i].first-xs[i-1].first);
		g[xs[i-1].second].emplace_back(xs[i].second, xs[i].first-xs[i-1].first);
		
		g[ys[i].second].emplace_back(ys[i-1].second, ys[i].first-ys[i-1].first);
		g[ys[i-1].second].emplace_back(ys[i].second, ys[i].first-ys[i-1].first);
	}
	printf("%lld", prim(n));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
