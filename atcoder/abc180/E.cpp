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

struct point {
  int x, y, z;
};

const int N = 17;
const long long inf = 1e15;

vector<point> p;
int n;
long long dp[1 << N][N];

long long dist(int i, int j) {
  return 1LL * abs(p[j].x-p[i].x) + abs(p[j].y-p[i].y) + max(0, p[j].z-p[i].z);
}

long long rek(int mask, int pos) {
  if (mask == (1 << n)-1) return dist(pos, 0);
  long long &ret = dp[mask][pos];
  if (ret != -1) return ret;
  ret = inf;
  for (int i = 1; i < n; ++i) {
    if (mask & (1 << i)) continue;
    ret = min(ret, dist(pos, i)+rek(mask | (1 << i), i));
  }
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    p.push_back({x, y, z});
  }
  printf("%lld", rek(1, 0));
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
