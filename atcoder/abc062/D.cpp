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

int a[3*N];
map<int, int> s[2];
map<int, int> q;

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < 3*n; ++i) {
		scanf("%d", a+i);
		++s[1][a[i]];
	}
	long long sum[2] = {};
	for (int i = 0; i < n; ++i) {
		sum[0] += a[i];
		++s[0][a[i]];
		if (--s[1][a[i]] == 0) s[1].erase(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		auto x = *s[1].rbegin();
		++q[x.first];
		if (--s[1][x.first] == 0) s[1].erase(x.first);
	}
	for (const auto &e: s[1]) {
		sum[1] += (long long)e.first*e.second;
	}
	long long ans = sum[0]-sum[1];
	debug(sum[0]);
	debug(sum[1]);
	for (int i = n; i < 2*n; ++i) {
		sum[0] += a[i];
		++s[0][a[i]];
		int x = (*s[0].begin()).first;
		sum[0] -= x;
		if (--s[0][x] == 0) s[0].erase(x);
		
		if (q.find(a[i]) != q.end()) {
			if (--q[a[i]] == 0) q.erase(a[i]);
		} else {
			if (--s[1][a[i]] == 0) s[1].erase(a[i]);
			sum[1] -= a[i];
			int x = (*q.begin()).first;
			sum[1] += x;
			if (--q[x] == 0) q.erase(x);
		}
		
		ans = max(sum[0]-sum[1], ans);
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
