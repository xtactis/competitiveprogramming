#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	string res;
	for (char c: s) {
		if (c == 'B') {
			if (res.size()) res.pop_back();
		} else {
			res.push_back(c);
		}
	}
	cout << res;
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
