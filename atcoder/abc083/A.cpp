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
	int a, b, c, d; cin >> a >> b >> c >> d;
	if (a+b > c+d) cout << "Left";
	else if (a+b < c+d) cout << "Right";
	else cout << "Balanced";
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
