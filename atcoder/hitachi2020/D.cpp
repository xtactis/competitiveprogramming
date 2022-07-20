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

vector<pair<long long, long long>> p;
vector<long long> A, B;

void solve() {
	long long n, t; scanf("%lld%lld", &n, &t);
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		if (a) {
			p.emplace_back(a, b);
		} else {
			B.push_back(1);
			B.push_back(b);
		}
	}
	sort(p.begin(), p.end());
	sort(B.begin(), B.end());
	long long ct = 0;
	for (int i = 0; i < (int)p.size(); ++i) {
		A.push_back(++ct);
		ct += p[i].first*ct+p[i].second;
		A.push_back(ct);
	}
	for (int i = 1; i < (int)B.size(); ++i) {
		B[i] += B[i-1];
	}
	int ans = 0;
	if (B.size()) {
		ans = upper_bound(B.begin(), B.end(), t)-B.begin();
		if (ans%2==0) {
			ans /= 2;
		} else {
			ans = (ans-1)/2;
		}
		debug(ans);
		debug(B[ans]);
		for (int i = 0; i < (int)A.size(); ++i) {
			long long ct = A[i];
			if (i%2==0) continue;
			if (ct > t) break;
			debug(t-ct);
			debug(upper_bound(B.begin(), B.end(), t-ct)-B.begin());
			int x = upper_bound(B.begin(), B.end(), t-ct)-B.begin();
			if (x%2==0) {
				x /= 2;
			} else {
				x = (x-1)/2;
			}
			debug(i);
			debug(x);
			debug(ans);
			debug((i+1)/2+x);
			ans = max(ans, (i+1)/2+x);
		}
	} else {
		for (int i = 0; i < (int)A.size(); ++i) {
			long long ct = A[i];
			if (i%2==0) continue;
			if (ct > t) break;
			ans = (i+1)/2;
		}
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
