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

void solve() {
	int h, w; scanf("%d%d", &h, &w);
	if (h > w) swap(h, w);
	long long ans = 2e18;
	for (long long i = 1; i < h; ++i) {
		long long a = i*w;
		long long b = (h-i)*(w/2);
		long long c = (h-i)*(w/2+w%2);
		//debug(a); debug(b); debug(c);
		ans = min(ans, max({a, b, c})-min({a, b, c}));
		b = ((h-i)/2)*w;
		c = ((h-i)/2+(h-i)%2)*w;
		ans = min(ans, max({a, b, c})-min({a, b, c}));
	}
	for (long long i = 1; i < w; ++i) {
		long long a = i*h;
		long long b = (w-i)*(h/2);
		long long c = (w-i)*(h/2+h%2);
		//debug(a); debug(b); debug(c);
		ans = min(ans, max({a, b, c})-min({a, b, c}));
		b = ((w-i)/2)*h;
		c = ((w-i)/2+(w-i)%2)*h;
		ans = min(ans, max({a, b, c})-min({a, b, c}));
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
