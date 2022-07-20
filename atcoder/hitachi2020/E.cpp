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
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < (1 << n)-1; ++i) {
		for (int j = 0; j < (1 << m)-1; ++j) {
			printf("%d", i%2);
		}
		puts("");
	}
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
