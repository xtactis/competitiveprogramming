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

void solve() {
	int a, b; scanf("%d%d", &a, &b);
	for (int i = 1; i < 1000000; ++i) {
		if ((int)(i*0.08) == a && (int)(i*0.1) == b) {
			printf("%d", i);
			return;
		}
	}
	printf("-1");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
