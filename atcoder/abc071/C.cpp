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

map<int, int> h;

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		++h[a];
	}
	priority_queue<int> q;
	long long ans = 0;
	for (const auto &e: h) {
		if (e.second < 2) continue;
		if (e.second > 3) ans = max(ans, (long long)e.first*e.first);
		q.push(e.first);
	}
	if (q.size() < 2) printf("%lld", ans);
	else {
		long long tmp = q.top(); q.pop();
		printf("%lld", max(ans, tmp*q.top()));
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
