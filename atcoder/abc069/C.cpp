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
	int d4 = 0, d2 = 0;
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		if (a%4==0) ++d4;
		else if (a%2==0) ++d2;
	}
	n -= d4+d2;
	if ((d2 && d4 >= n) || (!d2 && d4 >= n-1)) puts("Yes");
	else puts("No");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
