#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+45;
int a[N];
int h[N];

int main() {
  long long n, k; scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    --a[i];
  }
  int pos = 0; bool done = false;
  for (int i = 1; i <= k; ++i) {
    if (!done && h[pos]) {
      int cycle = i-h[pos];
      k = (k-i)%cycle;
      done = true;
      if (!k) break;
      else k = i+k;
    }
    //printf("%d -> ", pos+1);
    h[pos] = i;
    pos = a[pos];
  }
  printf("%d", pos+1); 
  return 0;
}
