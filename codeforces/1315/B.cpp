#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int enter, const string &s, int p) {
	int ret = 0;
	int istram = -1;
	for (int i = enter; i < (int)s.size()-1; ++i) {
		if (s[i] == 'B') {
			if (istram == 1) continue;
			ret += b;
			istram = 1;
		} else {
			if (istram == 0) continue;
			ret += a;
			istram = 0;
		}
		if (ret > p) return false;
	}
	//cout << "debug " << enter << ' ' << ret << ' ' << s << endl;
	return ret <= p;
}

void solve() {
	int a, b, p; cin >> a >> b >> p;
	string s; cin >> s;
	int lo = -1, hi = s.size();
	while (lo+1 < hi) {
		int mid = lo+(hi-lo)/2;
		if (check(a, b, mid, s, p)) hi = mid;
		else lo = mid;
	}
	cout << hi+1 << "\n";
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
