#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

const int N = 1234;
const int mod = 1e9+7;

vector<int> primes;
bool isnotprime[N];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	primes.push_back(2);
	for (int i = 0; i < N; i+=2) {
		isnotprime[i] = 1;
	}
	for (int i = 3; i*i < N; i+=2) {
		if (isnotprime[i]) continue;
		for (int j = i*i; j < N; j+=i) {
			isnotprime[j] = 1;
		}
	}
	for (int i = 3; i < N; i+=2) {
		if (isnotprime[i]) continue;
		primes.push_back(i);
	}
}

int h[N];

void solve() {
	int n; scanf("%d", &n);
	long long ans = 1;
	for (int i = 2; i <= n; ++i) {
		int m = i;
		for (int p: primes) {
			while (m > 0 && m % p == 0) {
				m /= p;
				++h[p];
			}
			if (m <= 0) break;
		}
	}
	for (int p: primes) {
		ans = (ans * ++h[p]) % mod;
	}
	printf("%lld", ans);
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
