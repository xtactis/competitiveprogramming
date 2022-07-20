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

const int N = 2e5+34;
const int P = 1e4+345;

long long a[N];
long long m[P];
string s;

void solve() {
	int n, p; cin >> n >> p >> s;
	long long exp = 1;
	long long cc = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; ++i) {
		s[i] -= '0';
		a[i] = s[i]*exp%p;
		(exp *= 10) %= p;
		++m[(cc += a[i]) %= p];
	}
	long long ans = 0;
	if (p == 2 || p == 5) {
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; ++i) {
			if (s[i] % p == 0) ans += i+1;
		}
	} else {
		for (int i = 0; i < p; ++i) {
			if (m[i] > 1) ans += m[i]*(m[i]-1)/2;
		}
		ans += m[0];
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
