#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int a[3][3];
set<int> s;
bool in(int x) {
	return !!s.count(x);
}

void solve() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int b; scanf("%d", &b);
		s.insert(b);
	}
	bool ans = false;
	for (int i = 0; i < 3; ++i) {
		ans |= in(a[i][0])&&in(a[i][1])&&in(a[i][2]);
		ans |= in(a[0][i])&&in(a[1][i])&&in(a[2][i]);
	}
	ans |= in(a[0][0])&&in(a[1][1])&&in(a[2][2]);
	ans |= in(a[2][0])&&in(a[1][1])&&in(a[0][2]);
	puts(ans?"Yes":"No");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
