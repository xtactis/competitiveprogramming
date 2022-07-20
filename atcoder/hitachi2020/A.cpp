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
	string s; cin >> s;
	if (s.size()%2) {
		cout << "No";
		return;
	}
	for (int i = 0; i < (int)s.size()-1; i+=2) {
		if (s[i] == 'h' && s[i+1] == 'i') continue;
		cout << "No";
		return;
	}
	cout << "Yes";
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
