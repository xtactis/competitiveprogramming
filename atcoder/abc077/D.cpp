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

int f(long long x) {
	if (!x) return 0;
	return x%10 + f(x/10);
}

const int N = 123412;

bool primes[123412];

void solve() {
	const int n = 70;
	for (int i = 3; i*i < N; i+=2) {
		if (i>3) primes[i-1] = true;
		if (primes[i]) continue;
		for (int j = i*i; j < N; j += i) {
			primes[j] = true;
		}
	}
	printf("\t");
	for (int i = 1; i <= n; ++i) {
		if (!primes[i]) continue;
		printf("%4d", i);
	}
	for (int i = 1; i <= n; ++i) {
		printf("\n");
		printf("%3d:\t", i);
		for (int j = 1; j <= n; ++j) {
			if (!primes[j]) continue;
			printf("%4d", f(i*j));
		}
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

/*
 * 6 -> 12 18 24 30 36 42 48 54 60
 * 6	3  9  6  3  9  6  12 9  6
 */
