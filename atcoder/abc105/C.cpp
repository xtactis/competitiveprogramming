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
  long long n; scanf("%lld", &n);
  if (!n) {
    printf("0");
    return;
  }
  vector<int> ans;
  if (n > 0) {
    for (long long i = 0;; ++i) {
      if (i && i%2==0) {
	n += 1LL << (i-1);
      }
      if (n/(1LL<<i) == 0) break;
      ans.push_back((n/(1LL<<i))%2);
    }  
  } else {
    n = -n;
    for (long long i = 0;; ++i) {
      if (i%2==1) {
	n += 1LL << (i-1);
      }
      if (n/(1LL<<i) == 0) break;
      ans.push_back((n/(1LL<<i))%2);
    }
  }
  for (int i = ans.size()-1; i >= 0; --i) {
    printf("%d", ans[i]);
  }
}

int main() {
  solve();
  return 0;
}

/*
1 -2 4 -8 16
  00
-10 1010
-9  1011
-8  1000
-7  1001
-6  1110
-5  1111
-4  1100
-3  1101
-2  0010
-1    11
0     00
1      1
2    110 
3    111
4    100
5    101
6  11010
7  11011
8  11000
9  11001
10 11110

0: n%2
1: ((n+2)/2)%2
2: ((n+2)/4)%2
3: ((n+8)/8)%2
4: ((n+8)/16)%2

  0: 00000 good
  1: 00001 good
 -1: 00001 bad, just add 1 to leftmost?
  4: 00100
 -5: 1
 10:
-10:

0(-1)10

10%2 = 0
10/2 = 5
5%2 = 1
5/-2 = -2
-2%2 = 0
-2/2 = -1
-1%2 = -1
-1/2 = 0

10(-1)

-5%2 = -1
-5/2 = -2
-2%2 = 0
-2/-2 = 1
1%2 = 1
1/2 = 0

 */
