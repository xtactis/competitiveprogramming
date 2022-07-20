#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

long long ans[10];
set<pair<int, int>> s;
int h, w, n;

int check(int u, int l, int a, int b) {
	if (u <= 0 || l <= 0) return -1;
	if (u+2 > h || l+2 > w) return -1;
	int cnt = 0;
	for (int i = u; i < u+3; ++i) {
		for (int j = l; j < l+3; ++j) {
			cnt += s.count(make_pair(i, j));
		}
	}
	return cnt;
}

void solve() {
	scanf("%d %d %d", &h, &w, &n);
	ans[0] = (long long)(h-2)*(w-2);
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		vector<int> v;
		for (int j = -2; j <= 0; ++j) {
			for (int k = -2; k <= 0; ++k) {
				v.push_back(check(a+j, b+k, a, b));
				if (v.back() == -1) v.pop_back();
			}
		}
		s.emplace(a, b);
		for (int e: v) {
			--ans[e];
			++ans[e+1];
		}
	}
	for (int i = 0; i < 10; ++i) {
		printf("%lld\n", ans[i]);
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
