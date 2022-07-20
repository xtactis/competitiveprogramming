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

vector<int> v;

void solve() {
  int n, k; scanf("%d %d", &n, &k);
  char state; scanf(" %c", &state);
  int count = 1;
  v.push_back(0);
  for (int i = 1; i < n; ++i) {
    char c; scanf(" %c", &c);
    if (state == c) {
      ++count;
    } else {
      v.push_back(count+v.back());
      count = 1;
      state = c;
    }
  }
  state -= '0';
  if (v.size()%2 == 0) state = !state;
  v.push_back(count+v.back());
  int ans = 0;
  for (int i = 1; i <= (int)v.size()-2*k; ++i) {
    state = !state;
    ans = max(ans, v[min((int)v.size()-1, i+2*k-state)]-v[i-1]);
  }
  if (ans == 0) ans = n;
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}

//    3 1 1 1 1 1  2  2  2
//[0] 3 4 5 6 7 8 10 12 14
