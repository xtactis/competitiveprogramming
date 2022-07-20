#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b; scanf("%d %d", &a, &b);
	if (a == b) {
		puts("0");
	} else if (a > b) {
		if ((a-b)%2==0) {
			puts("1");
		} else {
			puts("2");
		}
	} else {
		if ((b-a)%2==1) {
			puts("1");
		} else {
			puts("2");
		}
	}
}

int main() {
	int t = 1; scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
