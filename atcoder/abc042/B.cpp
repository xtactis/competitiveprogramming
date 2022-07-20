#include <bits/stdc++.h>
using namespace std;

string s[123];

void solve() {
	int n, l; cin >> n >> l;
	for (int i = 0; i < n; ++i) cin >> s[i];
	sort(s, s+n);
	for (int i = 0; i < n; ++i) cout << s[i];
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
