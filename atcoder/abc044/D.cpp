#include <bits/stdc++.h>
using namespace std;

void init() {

}

long long f(long long b, long long n) {
	if (b > n) return n;
	return f(b, n/b) + n%b;
}

void solve() {
	long long n, s; scanf("%lld %lld", &n, &s);
	if (n == s) {
		printf("%lld", n+1);
		return;
	}
	if (n < s) {
		printf("-1");
		return;
	}
	vector<long long> divs;
	divs.push_back(n-s);
	for (long long i = 2; i*i <= n; ++i) {
		if ((n-s)%i == 0) {
			divs.push_back((n-s)/i);
		}
		if (f(i, n) == s) {
			printf("%lld", i);
			return;
		}
	}
	divs.push_back(1);
	for (int i = (int)divs.size()-1; i >= 0; --i) {
		if (f(divs[i]+1, n) == s) {
			printf("%lld", divs[i]+1);
			return;
		}
	}
	printf("-1");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
