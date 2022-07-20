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

const int N = 8123;

vector<int> z[2];
bool dp[2][N*2+1];

bool solve() {
	string s; cin >> s;
	int x, y; cin >> x >> y;
	int cnt = 0, dir = 0; // 0 - horiz
	bool f = false;
	int rrr = 0;
	for (char c: s) {
		if (c == 'F') ++cnt;
		else {
			if (!f) {
				f = true;
				rrr = cnt;
			} else {
				z[dir].push_back(cnt);
			}
			dir = !dir;
			cnt = 0;
		}
	}
	if (f) {
		z[dir].push_back(cnt);
	} else {
		rrr = cnt;
	}
	dp[0][rrr] = dp[1][0] = 1;
	int sum[2] = {rrr, 0};
	// https://medium.com/swlh/solving-the-target-sum-problem-with-dynamic-programming-and-more-b76bd2a661f9
	for (int dir = 0; dir < 2; ++dir) {
		for (int num: z[dir]) {
			sum[dir] += num;
			for (int i = N*2; i >= num; --i) {
				dp[dir][i] |= dp[dir][i-num];
			}
		}
	}
	if (x > sum[0] || -x < -sum[0] || (x+sum[0])%2 == 1) return false;
	if (y > sum[1] || -y < -sum[1] || (y+sum[1])%2 == 1) return false;
	return dp[0][(x+sum[0])/2] && dp[1][(y+sum[1])/2];
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		cout << (solve()?"Yes":"No");
	}
	return 0;
}
