#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	if (s.size() == 2) {
		if (s[0] == s[1]) printf("1 2");
		else printf("-1 -1");
		return;
	}
	map<char, int> m;
	++m[s[0]]; ++m[s[1]];
	for (int i = 2; i < (int)s.size(); ++i) {
		++m[s[i]];
		if (m[s[i]] >= 2 || m[s[i-1]] >= 2 || m[s[i-2]] >= 2) {
			printf("%d %d", i-1, i+1);
			return;
		}
		--m[s[i-2]];
	}
	printf("-1 -1");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
