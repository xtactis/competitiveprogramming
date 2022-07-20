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

const int mod = 1e9+7;
const int N = 53;

string s[2];

void solve() {
	int n; cin >> n;
	long long ans = 1;
	cin >> s[0] >> s[1];
	int c = 3;
	for (int i = 0; i < n; ++i) {
		if (s[0][i] == s[1][i]) {
			(ans *= c) %= mod;
			c = 2;
		} else {
			if (c != 1) {
				(ans *= c*(c-1)) %= mod;
			} else {
				(ans *= 3) %= mod;
			}
			c = 1;
			++i;
		}
	}
	cout << ans;
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
