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

void solve() {
  int n; scanf("%d", &n);
  int sum = 0;
  for (int i = 1; sum < n; ++i) {
    sum += i;
  }
  if (sum > n) {
    printf("No");
    return;
  }
  int k = 1+(int)sqrt(2*n);
  printf("Yes\n%d\n", k);
  for (int sum = 1, i = 0; i < k; sum += i, ++i) {
    printf("%d ", k-1);
    for (int sum2 = 1, j = 0; j < k-1; ++j) {
      sum2 += j;
      if (j < i) {
	printf("%d ", sum+j);
      } else {
	printf("%d ", sum2+i);
      }
    }
    printf("\n");
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
