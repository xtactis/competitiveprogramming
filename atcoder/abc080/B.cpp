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

int f(int x) {
	if (x == 0) return 0;
	return x%10 + f(x/10);
}

void solve() {
	int n; scanf("%d", &n);
	printf(n%f(n)==0?"Yes":"No");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
