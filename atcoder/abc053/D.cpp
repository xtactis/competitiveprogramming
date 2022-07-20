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

const int N = 1e5+123;
int h[N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		++h[a];
	}
	int c = 0;
	for (int i = n = 0; i < N; ++i) {
		if (!h[i]) continue;
		if (h[i]%2) ++n;
		else ++c;
	}
	printf("%d", n+c-c%2);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
