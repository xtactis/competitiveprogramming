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

bool h[26];

void solve() {
	string s; cin >> s;
	for (char c: s) {
		h[c-'a'] = true;
	}
	for (int i = 0; i < 26; ++i) {
		if (!h[i]) {
			putchar(i+'a');
			return;
		}
	}
	puts("None");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
