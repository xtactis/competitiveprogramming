#include <bits/stdc++.h>
using namespace std;

vector<bool> isprime(1e5, true);
set<int> primes;
vector<int> ans;

const int N = 1e9;

void print() {
	printf("%d\n", (int)ans.size());
	for (int e: ans) printf("%d ", e);
}

bool checkPrime(int x) {
	if (x < 2) return false;
	if (primes.count(x)) return true;
	for (int p: primes) {
		if (p*p > x) break;
		if (x % p == 0) return false;
	}
	return true;
}

void solve() {
	int n; scanf("%d", &n);	
	primes.insert(2);
	for (long long i = 3; i*i <= N; i+=2) {
		if (isprime[i]) {
			primes.insert(i);
			for (long long j = i*i; j*j <= N; j += i) { 
				isprime[j] = false;
			}
		}
	}
	if (checkPrime(n)) {
		ans.push_back(n);
		goto end;
	}
	for (int p: primes) {
		//printf("%d ", p);
		if (checkPrime(n-p)) {
			ans.push_back(p);
			ans.push_back(n-p);
			goto end;
		}
		for (int q: primes) {
			if (checkPrime(n-p-q)) {
				ans.push_back(p);
				ans.push_back(q);
				ans.push_back(n-p-q);
				goto end;
			}
		}
	}
	end:
	print();
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
