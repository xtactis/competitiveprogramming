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

const int N = 52;
int n, m, q;
int a[N], b[N], c[N], d[N];
vector<int> v;

int rek(int last = 1, int depth = 0) {
  int ret = 0;
  if (depth == n) {
    for (int i = 0; i < q; ++i) {
      if (v[b[i]]-v[a[i]] == c[i])
	ret += d[i];
    }
    return ret;
  }
  for (int i = last; i <= m; ++i) {
    v.push_back(i);
    ret = max(ret, rek(i, depth+1));
    v.pop_back();
  }
  return ret;
}

void solve() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", a+i, b+i, c+i, d+i);
    --a[i]; --b[i];
  }
  printf("%d", rek());
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
