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
int a[N], b[N];

void solve() {
	int n; scanf("%d", &n);
	int firstNonZero = n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		if (a[i] && firstNonZero == n) firstNonZero = i;
	}
	if (firstNonZero == n) {
		cout << (long long)n*(n+1)/2;
		return;
	}
	// neg 1st
	long long s = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
		if (i % 2 == 0) { // neg
			ans += s<0?0:(s+1);
			s -= s<0?0:(s+1);
		} else {
			ans += s>0?0:(-s+1);
			s += s>0?0:(-s+1);
		}
		debug(s);
	}
	// pos 1st
	long long cur = s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
		if (i % 2 == 0) { // pos
			cur += s>0?0:(-s+1);
			s += s>0?0:(-s+1);
		} else {
			cur += s<0?0:(s+1);
			s -= s<0?0:(s+1);
		}
	}
	cout << min(cur, ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
