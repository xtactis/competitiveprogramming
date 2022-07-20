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

const int N = 1e9;

bool is_not_prime[N+23];

void solve() {
  for (long long i = 3; i <= N; i+=2) {
    if (is_not_prime[i]) continue;
    if (i*i <= N) {
      for (long long j = i*i; j <= N; j+=i)
	is_not_prime[j] = true;
    }
  }
  printf("%d", is_not_prime[N]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
