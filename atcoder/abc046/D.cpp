#include <bits/stdc++.h>
using namespace std;

string s;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	cin >> s;
	int ans = 0;
	char cur = 'g';
	for (char c: s) {
		if (c == 'g' && cur == 'p') ++ans;
		else if (c == 'p' && cur == 'g') --ans;
		cur = cur == 'g' ? 'p' : 'g';
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
