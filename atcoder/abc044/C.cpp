#include <bits/stdc++.h>
using namespace std;

int a[60];
int A, n;

long long dp[50][2500][50];

void init() {
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 2500; ++j) {
			for (int k = 0; k < 50; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
}

long long rek(int i, int sum, int cnt) {
	if (i < 0) return 0;
	if (dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
	return dp[i][sum][cnt] = (sum+a[i] == A*(cnt+1)) + rek(i-1, sum+a[i], cnt+1) + rek(i-1, sum, cnt);
}

void solve() {scanf("%d %d", &n, &A);
	for (int i = 0; i < n; ++i) scanf("%d", a+i);
	printf("%lld", rek(n-1, 0, 0));
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
