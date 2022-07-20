#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	string s[3]; cin >> s[0] >> s[1] >> s[2];
	unsigned int p[3] = {};
	int move = 0;
	while (true) {
		if (p[move] >= s[move].size()) {
			printf("%c", move+'A');
			return;
		}
		move = s[move][p[move]++]-'a';
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
