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

int n;

int minimum(array<int, 3> a, array<int, 3> b) {
  int ans = n, ret = n;
  function<void(array<int, 3>&, array<int, 3>&)> foos[] = {
			[&ret](array<int, 3> &a, array<int, 3> &b) {
			  int x = min(b[0], a[1]);
			  b[0] -= x;
			  a[1] -= x;
			  ret -= x;
			},
			[&ret](array<int, 3> &a, array<int, 3> &b) {
			  int x = min(b[1], a[2]);
			  b[1] -= x;
			  a[2] -= x;
			  ret -= x;
			},
			[&ret](array<int, 3> &a, array<int, 3> &b) {
			  int x = min(b[2], a[0]);
			  b[2] -= x;
			  a[0] -= x;
			  ret -= x;
			},
			[&ret](array<int, 3> &a, array<int, 3> &b) {
			  int x = min(a[0], b[0]);
			  a[0] -= x;
			  b[0] -= x;
			  ret -= x;
			},
			[&ret](array<int, 3> &a, array<int, 3> &b) {
			  int x = min(a[1], b[1]);
			  a[1] -= x;
			  b[1] -= x;
			  ret -= x;
			},
			[&ret](array<int, 3> &a, array<int, 3> &b) {
			  int x = min(a[2], b[2]);
			  a[2] -= x;
			  b[2] -= x;
			  ret -= x;
			},
  };
  int ind[6] = {0, 1, 2, 3, 4, 5};
  do {
    ret = n;
    array<int, 3> _a = a, _b = b;
    for (int i = 0; i < 6; ++i) {
      foos[ind[i]](_a, _b);
    }
    ans = min(ans, ret);
  } while (next_permutation(ind, ind+6));
  return ans;
}

int maximum(array<int, 3> a, array<int, 3> b) {
  return min(a[0], b[1])+min(a[1], b[2])+min(a[2], b[0]);
}

void solve() {
  scanf("%d", &n);
  array<int, 3> a, b;
  for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < 3; ++i) scanf("%d", &b[i]);
  printf("%d %d", minimum(a, b), maximum(a, b));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
