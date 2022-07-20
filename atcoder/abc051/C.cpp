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

const int inf = 2e9;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

map<pair<int, int>, bool> m;
string ans;

map<pair<int, int>, bool> bio;
map<pair<int, int>, pair<int, int>> p;

void bfs(int sx, int sy, int tx, int ty) {
	m[make_pair(sx, sy)] = false;
	m[make_pair(tx, ty)] = false;
	bio.clear();
	p.clear();
	queue<pair<int, int>> q;
	p[make_pair(sx, sy)] = make_pair(inf, inf);
	bio[make_pair(sx, sy)] = true;
	q.emplace(sx, sy);
	while (!q.empty()) {
		pair<int, int> u = q.front(); q.pop();
		if (u.first == tx && u.second == ty) {
			string s;
			while (!(u.first == inf && u.second == inf)) {
				debug(u.first);
				debug(u.second);
				pair<int, int> par = p[u];
				m[u] = true;
				if (par.first > u.first) s.push_back('L');
				if (par.first < u.first) s.push_back('R');
				if (par.second > u.second) s.push_back('D');
				if (par.second < u.second) s.push_back('U');
				u = par;
			}
			for (int i = (int)s.size()-1; i >= 0; --i) {
				ans.push_back(s[i]);
			}
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int vx = u.first+dx[i], vy = u.second+dy[i];
			pair<int, int> v = make_pair(vx, vy);
			if (bio[v]) continue;
			if (m[v]) continue;
			bio[v] = true;
			q.push(v);
			p[v] = u;
		}
	}
	
}

void solve() {
	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	for (int i = sy; i < ty; ++i) cout << 'U';
	for (int i = sx; i < tx; ++i) cout << 'R';
	for (int i = sy; i < ty; ++i) cout << 'D';
	for (int i = sx; i < tx; ++i) cout << 'L';
	cout << 'L';
	for (int i = sy; i < ty+1; ++i) cout << 'U';
	for (int i = sx; i < tx+1; ++i) cout << 'R';
	cout << 'D';
	cout << 'R';
	for (int i = sy; i < ty+1; ++i) cout << 'D';
	for (int i = sx; i < tx+1; ++i) cout << 'L';
	cout << 'U';
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
