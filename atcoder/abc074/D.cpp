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

const int N = 321;
const int inf = 2e9;

long long a[N][N];
bool important[N][N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%lld", a[i]+j);
			important[i][j] = 1;
		}
	}
	long long sum = 0;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			if (i == k) continue;
			for (int j = 0; j < n; ++j) {
				if (j == i || j == k) continue;
				if (a[i][j] > a[i][k]+a[k][j]) {
					printf("-1");
					return;
				}
				if (a[k][i] == a[k][j]+a[j][i]) important[k][i] = 0;
			}
			if (important[k][i]) sum += a[k][i];
		}
	}

	printf("%lld", sum/2);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
