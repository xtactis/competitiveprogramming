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

const int N = 5e3+34;

int a[N];

int rek(int i, int s) {
	if (s <= 0) return 0;
	if (i < 0) return -2e9;
	int y = rek(i-1, s);
	if (y > 0) return y;
	int x = rek(i-1, s-a[i]);
	return x<0?0:(x+1);
}

void solve() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	sort(a, a+n, greater<int>());
	printf("%d", rek(n-1, k));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
