#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+234;

int fact[N];

void factorial() {
	fact[0] = 1;
	for (long long i = 1; i < N; ++i) {
		fact[i] = (fact[i-1] * i) % mod;
	}
}

long long binpow(long long b, long long e) {
	if (!e) return 1;
	if (e&1) return b*binpow(b, e-1)%mod;
	return binpow(b*b%mod, e/2);
}

int comb(int n, int k) {
	long long bro = fact[n];
	long long naz = ((long long)fact[k]*fact[n-k])%mod;
	return (bro*binpow(naz, mod-2))%mod;
}

void solve() {
	factorial();
	int h, w, a, b; scanf("%d %d %d %d", &h, &w, &a, &b);
	long long ans = 0;
	for (int i = b+1; i <= w; ++i) {
		int n = h-a, m = i;
		long long fi = comb(m+n-2, n-1);
		n = a, m = w-i+1;
		long long se = comb(m+n-2, n-1);
		ans = (ans + fi*se)%mod;
	}
	printf("%lld", ans);
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
