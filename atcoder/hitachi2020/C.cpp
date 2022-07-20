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

const int N = 2e5+345;

vector<int> g[N];
int ans[N];

int bio[N];
void dfs(int u, int c=1) {
	bio[u] = c;
	for (int v: g[u]) {
		if (bio[v]) continue;
		dfs(v, c==1?2:1);
	}
}

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	dfs(0);
	int r = 0;
	int c = 1;
	for (int i = 0; i < n; ++i) if (bio[i] == c) ++r;
	if (r > n-r) {
		r = n-r;
		c = 2;
	}
	debug(r);
	if (r <= n/3) {
		int k = 1;
		for (int i = 0; i < n; ++i) {
			if (bio[i] == c && k*3 <= n) {
				ans[i] = k*3; ++k;
			}
		}
	} else {
		int k = 0, q = 0;
		for (int i = 0; i < n; ++i) {
			if (bio[i] == c) {
				if (k*3+1 <= n) {
					ans[i] = k*3+1;
					++k;
				}
			} else {
				if (q*3+2 <= n) {
					ans[i] = q*3+2;
					++q;
				}
			}
		}
	}
	set<int> s;
	for (int i = 1; i <= n; ++i) s.insert(i);
	for (int i = 0; i < n; ++i) {
		if (ans[i]) s.erase(ans[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (!ans[i]) {
			ans[i] = *s.begin();
			s.erase(s.begin());
		}
		printf("%d ", ans[i]);
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
