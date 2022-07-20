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
	string o, e; cin >> o >> e;
	for (int i = 1; i <= (int)o.size()+(int)e.size(); ++i) {
		if (i%2==0) {
			cout << e[i/2-1];
		} else {
			cout << o[i/2];
		}
	}
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
