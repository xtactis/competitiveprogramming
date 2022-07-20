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
	string a, b; cin >> a >> b;
	if (a.size() > b.size()) {
		cout << "GREATER";
		return;
	}
	if (a.size() < b.size()) {
		cout << "LESS";
		return;
	}
	if (a == b) {
		cout << "EQUAL";
		return;
	}
	for (int i = 0; i < (int)a.size(); ++i) {
		if (a[i] == b[i]) continue;
		if (a[i] < b[i]) {
			cout << "LESS";
		} else {
			cout << "GREATER";
		}
		break;
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
