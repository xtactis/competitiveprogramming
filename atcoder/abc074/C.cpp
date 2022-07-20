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

void solve() {
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	a*=100; b*=100;
	int sugar = 0, ans = a;
	double p = 0;
	for (int i = 0; i <= f; i+=a) {
		for (int j = 0; j <= f; j+=b) {
			for (int k = 0; k <= f; k+=c) {
				for (int l = 0; l <= f; l+=d) {
					if (i+j+k+l > f) continue;
					if (i+j == 0 || 100.*(k+l)/(i+j) > e) continue;
					if ((100.*(k+l))/(i+j+k+l) > p) {
						p = (100.*(k+l))/(i+j+k+l);
						sugar = k+l;
						ans = i+j+k+l;
					}
				}
			}
		}
	}
	printf("%d %d", ans, sugar);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
