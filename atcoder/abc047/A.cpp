#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int a[3]; scanf("%d%d%d", a, a+1, a+2);
	sort(a, a+3);
	puts(a[0]+a[1]==a[2] ? "Yes" : "No");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
