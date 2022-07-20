#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void solve() {
	set<int> s; int a;
	cin >> a; s.insert(a);
	cin >> a; s.insert(a);
	cin >> a; s.insert(a);
	cout << s.size();
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
