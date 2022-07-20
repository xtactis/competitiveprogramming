#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void solve() {
	char a, b, c, d; scanf(" %c%c%c%c", &a, &b, &c, &d);
	a -= '0'; b -= '0'; c -= '0'; d -= '0';
	for (int i = -1; i < 2; i+=2) {
		for (int j = -1; j < 2; j+=2) {
			for (int k = -1; k < 2; k+=2) {
				if (a+i*b+j*c+k*d != 7) continue;
				printf("%d%+d%+d%+d=7", a, i*b, j*c, k*d);
				return;
			}
		}
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
