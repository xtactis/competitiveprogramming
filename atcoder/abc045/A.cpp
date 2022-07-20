#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int a, b, h; scanf("%d %d %d", &a, &b, &h);
	printf("%d", (a+b)*h/2);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
