#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+32;

void solve() {
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int ma = 1, mb = 1, mc = 1, dist = a+b+c-3;
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; j+=i) {
			if (abs(a-i)+abs(b-j)+min(c%j, j-c%j) < dist) {
				dist = abs(a-i)+abs(b-j)+min(c%j, j-c%j);
				ma = i; mb = j; mc = c%j < j-c%j ? c-c%j : c+(j-c%j);
			}
		}
	}
	printf("%d\n%d %d %d\n", dist, ma, mb, mc);
}

int main() {
	int t = 1; scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
