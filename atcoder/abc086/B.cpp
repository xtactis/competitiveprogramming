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

void solve() {
	int a, b; cin >> a >> b;
	int x = a*pow(10, 1+floor(log10(b)))+b;
	int y = sqrt(x);
	debug(x);
	debug(y);
	cout << (y*y==x?"Yes":"No");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
