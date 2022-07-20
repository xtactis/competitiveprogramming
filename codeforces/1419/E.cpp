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

long long lcm(long long x, long long y) {
  return x/__gcd(x, y)*y;
}

void solve() {
  int n; scanf("%d", &n);
  set<long long> divs;
  for (int i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    divs.insert(i);
    divs.insert(n/i);
  }
  divs.insert(n);
  vector<long long> ans;
  ans.push_back(*divs.begin());
  divs.erase(divs.begin());
  ans.push_back(*divs.begin());
  divs.erase(divs.begin());
  int i = 1;
  while (!divs.empty()) {
    if (__gcd(ans[i], ans[i-1]) == 1) {
      long long ll = lcm(ans[i], ans[i-1]);
      for (long long l = ll; l <= n; l += ll) {
	if (divs.count(l)) {
	  long long t = ans.back();
	  ans.pop_back();
	  ans.push_back(l);
	  divs.erase(l);
	  ans.push_back(t);
	  ++i;
	  break;
	}
      }
    }
    if (divs.empty()) break;
    ans.push_back(*divs.begin());
    divs.erase(divs.begin());
    ++i;
  }
  int anscnt = 0;
  for (int i = 1; i < (int)ans.size(); ++i) {
    if (__gcd(ans[i], ans[i-1]) == 1) ++anscnt;
  }
  if (__gcd(ans[0], ans.back()) == 1) ++anscnt;
  for (long long x: ans) printf("%lld ", x);
  printf("\n%d\n", anscnt);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
