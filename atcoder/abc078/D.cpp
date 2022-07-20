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

const int N = 2e3+45;

int a[N];
int n, z, w;
int dp[N][2];
int c[N][N];

void mmax(int &x, int y) {
	if (x == -1) x = y;
	x = max(x, y);
}

void mmin(int &x, int y) {
	if (x == -1) x = y;
	x = min(x, y);
}

int rek(int i, int p, int prev) {
	if (i == n-1) return abs(a[i]-a[prev]);
	int &ret = dp[i][p];
	if (ret != -1) return ret;
	for (int j = i+1; j < n; ++j) {
		if (p) mmin(ret, rek(j, !p, i));
		else mmax(ret, rek(j, !p, i));
	}
	return ret;
}

void solve() {
	for (int i = 0; i < N; ++i) for (int j = 0; j < 2; ++j) dp[i][j] = -1;
	scanf("%d%d%d", &n, &z, &w);
	a[0] = z;
	a[1] = w;
	n += 2;
	for (int i = 2; i < n; ++i) {
		scanf("%d", a+i);
	}
	printf("%d", rek(1, 0, 0));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
