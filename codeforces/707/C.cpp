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

vector<int> v;
set<long long> s;

bool check1(long long z, long long w) {
	if (z > w) return false;
	if (w%2 != z%2) return false;
	long long x = (w+z)/2, y = (w-z)/2;
	if (x <= 0 || y <= 0) return false;
	debug(w);
	debug(z);
	printf("%lld %lld", x, y);
	return true;
}

void solve() {
	int n; scanf("%d", &n);
	for (int i = 1; i*i <= n; ++i) {
		if (n%i) continue;
		v.push_back(i); v.push_back(n/i);
	}
	long long x = n; x*=x;
	for (int e: v) {
		for (int f: v) {
			long long y = e; y*=f;
			if (check1(y, x/y)) return;
		}
	}
	printf("-1");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
