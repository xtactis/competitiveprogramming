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
	int n; scanf("%d", &n);
	set<int> s;
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		if (s.count(a)) s.erase(a);
		else s.insert(a);
	}
	printf("%d", s.size());
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
