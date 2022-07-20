#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void solve() {
	string sp, t; cin >> sp >> t;
	string s = "";
	if (t.size() > sp.size()) {
		cout << "UNRESTORABLE";
		return;
	}
	for (int i = 0; i < (int)(sp.size()-t.size()+1); ++i) {
		string cur = sp; bool f = true;
		for (int j = 0; j < (int)t.size(); ++j) {
			if (cur[i+j] == '?') {
				cur[i+j] = t[j];
			}
			if (cur[i+j] == t[j]) continue;
			f = false;
			break;
		}
		if (f) {
			for (char &c: cur) if (c == '?') c = 'a';
			if (s.size()) s = min(cur, s);
			else s = cur;
		}
	}
	if (s.size()) cout << s;
	else cout << "UNRESTORABLE";
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
