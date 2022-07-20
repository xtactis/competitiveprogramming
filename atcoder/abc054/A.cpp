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

void solve() {
	int a, b; cin >> a >> b;
	if (a == 1) a = 14;
	if (b == 1) b = 14;
	if (a > b) cout << "Alice";
	if (a == b) cout << "Draw";
	if (a < b) cout << "Bob";
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
