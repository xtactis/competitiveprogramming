#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

const int mod = 1e9+7;
const int N = 1e5+234;
int a[N], h[N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		if (++h[a[i]] > 2) {
			puts("0");
			return;
		}
	}
	if (n%2 && h[0] != 1) {
		puts("0");
		return;
	}
	if (n%2==0 && h[0] != 0) {
		puts("0");
		return;
	}
	long long ans = 1;
	for (int i = 0; i < n/2; ++i) {
		ans = (ans*2)%mod;
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
