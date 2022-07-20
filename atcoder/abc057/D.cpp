#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

const int N = 53;
long long C[N+1][N+1];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	C[0][0] = 1;
	for (int n = 1; n <= N; ++n) {
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k < n; ++k)
			C[n][k] = C[n-1][k-1] + C[n-1][k];
	}
}


long long v[N];
map<long long, int> m, used;

long long count() {
	long long num = 1;
	for (const auto &e: used) {
		int k = e.second;
		if (k > m[e.first]-k) k = m[e.first]-k;
		if (e.second) num *= C[m[e.first]][k];
	}
	return num;
}

void solve() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", v+i);
		++m[v[i]];
	}
	sort(v, v+n, greater<long long>());
	long long s = 0;
	set<long long> z;
	for (int i = 0; i < a; ++i) {
		s += v[i];
		++used[v[i]];
		z.insert(v[i]);
	}
	double ans = 1.0*s/a;
	long long cnt = count();
	if (z.size() == 1) {
		while (used[v[0]] < m[v[0]] && used[v[0]] < b) {
			++used[v[0]];
			cnt += count();
		}
	}
	printf("%.10lf\n%lld", ans, cnt);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
