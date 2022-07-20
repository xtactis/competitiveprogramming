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

const int N = 123;
int a[N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a+i);
	printf("%d", *max_element(a, a+n)-*min_element(a, a+n));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
