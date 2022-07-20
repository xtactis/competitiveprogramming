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

const int N = 1e4+23;

bool prime[N];
vector<int> primes;

void SieveOfEratosthenes(){
  for (int p=2; p*p<=N; p++){
    if (prime[p] == false) {
      primes.push_back(p);
      for (int i=p*2; i<=N; i += p)
	prime[i] = true;
    }
  }
}

bool check(int x, int z, const vector<int> &c) {
  int y = x, cnt = 0;
  for (int i = z-1; i >= 0; --i) {
    while (y >= c[i]) y -= c[i], ++cnt;
  }
  for (int i = c.size()-1; i >= 0; --i) {
    while (x >= c[i]) x -= c[i], --cnt;
  }
  return cnt < 0;
}

void solve() {
  int n; scanf("%d", &n);
  vector<int> c;
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    c.push_back(x);
  }
  for (int i = 2; i < n; ++i) {
    if (c[i] <= c[i-1]+c[i-2] || check(c[i]+c[i-1]-1, i, c)) {
      puts("NE");
      return;
    }
  }
  puts("DA");
}

int main() {
  //SieveOfEratosthenes();
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
