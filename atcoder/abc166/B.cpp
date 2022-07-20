#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int N = 1e2+34;
int h[N];

void solve() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
	int d; scanf("%d", &d);
	for (int j = 0; j < d; ++j) {
	    int a; scanf("%d", &a);
	    ++h[a-1];
	}
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
	ans += !h[i];
    }
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
