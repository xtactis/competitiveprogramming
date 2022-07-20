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

const int N = 543;

pair<int, int> c[N], s[N];

int dist(int i, int j) {
	return abs(s[i].first-c[j].first)+abs(s[i].second-c[j].second);
}

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		s[i] = make_pair(u, v);
	}
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		c[i] = make_pair(u, v);
	}
	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int j = 1; j < m; ++j) {
			if (dist(i, j) < dist(i, cur)) cur = j;
		}
		debug(dist(i, cur));
		printf("%d\n", cur+1);
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
