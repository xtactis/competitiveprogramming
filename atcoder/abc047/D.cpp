#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	int n, t; scanf("%d %d", &n, &t);
	int minc = 2e9, maxc = 0;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		if (a < minc) {
			if (maxc) {
				v.push_back(maxc-minc);
			}
			minc = maxc = a;
		}
		if (a > maxc) maxc = a;
	}
	v.push_back(maxc-minc);
	sort(v.begin(), v.end(), greater<int>());
	int ans = 1, c = v[0];
	for (int i = 1; v[i] == c; ++i) ++ans;
	printf("%d", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
