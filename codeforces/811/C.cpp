#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+123;

int a[N], f[N], l[N], n;

int dp[N];

int rek(int i) {
	if (i >= n) return 0;
	if (dp[i] != -1) return dp[i];
	if (i != f[a[i]]) return dp[i] = rek(i+1);
	set<int> s;
	int ret = 0;
	int end = l[a[i]];
	for (int j = f[a[i]]; j <= end; ++j) {
		if (s.count(a[j])) continue;
		if (f[a[j]] < f[a[i]]) {
			return dp[i] = rek(i+1);
		}
		end = max(end, l[a[j]]);
		ret ^= a[j];
		s.insert(a[j]);
	}
	return dp[i] = max(ret+rek(end+1), rek(i+1));
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < N; ++i) {
		dp[i] = f[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		l[a[i]] = i;
		if (f[a[i]] != -1) continue;
		f[a[i]] = i;
	}
	printf("%d", rek(0));
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
