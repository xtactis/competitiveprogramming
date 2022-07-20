#include <bits/stdc++.h>
using namespace std;

int a[1234];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	long long ans = 2e15;
	for (int i = -100; i <= 100; ++i) {
		long long cur = 0;
		for (int j = 0; j < n; ++j) {
			cur += (i-a[j])*(i-a[j]);
		}
		ans = min(ans, cur);
	}
	printf("%lld", ans);
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
