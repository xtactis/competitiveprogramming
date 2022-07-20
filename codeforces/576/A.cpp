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

const int N = 1e3+34;

bool nprime[N*N];
vector<int> p;

void solve() {
	int n; scanf("%d", &n);
	if (n == 1) {
		printf("0");
		return;
	}
	int x = n*n;
	for (int j = 2; j <= n; j*=2) p.push_back(j);
	for (int i = 3; i*i <= x; i+=2) {
		if (nprime[i]) continue;
		for (int j = i; j <= n; j*=i) p.push_back(j);
		for (int j = i*i; j <= x; j+=i) nprime[j] = true;
	}
	printf("%d\n", (int)p.size());
	for (int e: p) printf("%d ", e);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
