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

const int mod = 1e9+7;

void solve() {
	long long a, b;
	cin >> a; b = a;
	cin >> a; (b *= a) %= mod;
	cin >> a; (b *= a) %= mod;
	cout << b;
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
