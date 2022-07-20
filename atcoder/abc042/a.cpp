#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a[3]; scanf("%d %d %d", a, a+1, a+2);
	sort(a, a+3);
	puts((a[0] == 5 && a[1] == 5 && a[2] == 7)?"YES":"NO");
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
