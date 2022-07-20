#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

string a[53], b[54];
int n, m; 

bool check(int x, int y) {
	for (int i = x; i < x+m; ++i)
		for (int j = y; j < y+m; ++j)
			if (a[i][j] != b[i-x][j-y])
				return false;
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i <= n-m; ++i) {
		for (int j = 0; j <= n-m; ++j) {
			if (check(i, j)) {
				cout << "Yes";
				return;
			}
		}
	}
	cout << "No";
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
