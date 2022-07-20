#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	string s; cin >> s;
	int n = s.size();
	for (int i = 0; i < n;) {
		if (s.substr(i, 7) == "dreamer" && (i+7 >= n || s[i+7] == 'd' || s[i+7] == 'e')) {
			i+=7;
		} else if (s.substr(i, 5) == "dream" && (i+5 >= n || s[i+5] == 'd' || s[i+5] == 'e')) {
			i+=5;
		} else if (s.substr(i, 6) == "eraser" && (i+6 >= n || s[i+6] == 'd' || s[i+6] == 'e')) {
			i+=6;
		} else if (s.substr(i, 5) == "erase" && (i+5 >= n || s[i+5] == 'd' || s[i+5] == 'e')) {
			i+=5;
		} else {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
