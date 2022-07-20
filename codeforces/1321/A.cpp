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

int r[123], b[123], bb, rr;

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", r+i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b+i);
	}
	for (int i = 0; i < n; ++i) {
		if (!r[i] && b[i]) ++bb;
		if (!b[i] && r[i]) ++rr;
	}
	if (rr == 0) {
		puts("-1");
	} else if (rr > bb) {
		puts("1");
	} else if (rr == bb) {
		puts("2");
	} else {
		printf("%d\n", (bb-rr)/rr+2);
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
