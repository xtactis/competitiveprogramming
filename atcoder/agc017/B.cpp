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

bool solve() {
  long long n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  --n;
  if (a > b) swap(a, b);
  long long high = d*n;
  if (a+high < b) return false;
  long long mid = c*n;
  long long low = d*(n-1)-c;
  if (mid <= low) return true;
  long long k = (high-b+a)/(high-low);
  return high-k*(high-low) >= b-a && mid-k*(high-low) <= b-a;
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    puts(solve()?"YES":"NO");
  }
  return 0;
}
