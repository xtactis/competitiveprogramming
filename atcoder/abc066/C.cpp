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

const int N = 2e5+23;

int a[N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	if (n%2) {
		for (int i = n-n%2; i >= 0; i-=2) printf("%d ", a[i]);
		for (int i = 1; i < n; i+=2) printf("%d ", a[i]);
	} else {
		for (int i = n-!(n%2); i > 0; i-=2) printf("%d ", a[i]);
		for (int i = 0; i < n; i+=2) printf("%d ", a[i]);
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
