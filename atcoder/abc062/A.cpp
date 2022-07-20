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

bool g1(int x) {
	return (x <= 7 && x&1) || (x >= 8 && x%2==0);
}

void solve() {
	int x, y; scanf("%d%d", &x, &y);
	if (x == 2 || y == 2) {
		puts("No");
		return;
	}
	if (g1(x)^g1(y)) puts("No");
	else puts("Yes");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
