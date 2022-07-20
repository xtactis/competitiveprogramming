#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;

int a[N];
priority_queue<pair<int, int>, vector<pair<int, int>>> p;
set<int> s;

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	for (int i = 0; i < n; ++i) {
		int t; scanf("%d", &t);
		p.emplace(t, a[i]);
	}
	long long ans = 0;
	while (p.size()) {
		auto e = p.top(); p.pop();
		if (s.count(e.second)) {
			ans += e.first;
			++e.second;
			p.push(e);
		} else {
			s.insert(e.second);
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
