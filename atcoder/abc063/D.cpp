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

int n, a, b; 
int h[N];

bool check(long long t) {
	int c = t;
	for (int i = 0; i < n; ++i) {
		if (h[i]-t*b <= 0) break;
		c -= (h[i]-t*b+(a-b-1))/(a-b);
		if (c < 0) return false;
	}
	return true;
}

void solve() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
		scanf("%d", h+i);
	}
	sort(h, h+n, greater<int>());
	int lo = 0, hi = 1e9+1;
	while (lo+1 < hi) {
		int mid = (lo+hi)/2;
		if (check(mid)) hi = mid;
		else lo = mid;
	}
	printf("%d", hi);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
