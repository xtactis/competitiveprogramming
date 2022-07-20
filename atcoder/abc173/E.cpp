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

const int N = 2e5+23;
const int mod = 1e9+7;

int a[N];

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  int z = 0;
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (!a[i]) ++z;
  }
  if (n-z < k) {
    puts("0");
    return;
  }
  if (k == n) {
    for (int i = 0; i < n; ++i) {
      ans = (ans * a[i]) % mod;
    }
    printf("%lld", (ans+mod)%mod);
    return;
  }
  sort(a, a+n);
  if (a[n-1] <= 0 && k%2) {
    for (int i = n-1; i >= 0 && k; --i) {
      ans = (ans * a[i]) % mod;
      --k;
    }
    printf("%lld", (ans+mod)%mod);
    return;
  }
  if (a[0] >= 0) {
    for (int i = n-1; i >= 0 && k; --i) {
      ans = (ans * a[i]) % mod;
      --k;
    }
    printf("%lld", (ans+mod)%mod);
    return;
  }
  vector<long long> negs, poss;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      negs.push_back(a[i]);
    } else if (a[i] > 0) {
      poss.push_back(a[i]);
    }
  }
  sort(negs.begin(), negs.end());
  sort(poss.begin(), poss.end(), greater<long long>());
  int i = 0, j = 0;
  while (k > 0) {
    if (i < negs.size() && j < poss.size()) {
      if (k > 1) {
	if (i < negs.size()-1) {
	  if (j < poss.size()-1) {
	    if (negs[i]*negs[i+1] > poss[j]*poss[j+1]) {
	      ans = ans * negs[i] % mod * negs[i+1] % mod;
	      i += 2;
	    } else {
	      ans = ans * poss[j] % mod * poss[j+1] % mod;
	      j += 2;
	    }
	    k -= 2;
	  } else {
	    if (negs[i]*negs[i+1] > poss[j]) {
	      ans = ans * negs[i] % mod * negs[i+1] % mod;
	      i += 2;
	      k -= 2;
	    } else {
	      ans = ans * poss[j++] % mod;
	      --k;
	    }
	  }
	} else {
	  ans = ans * poss[j++] % mod;
	  --k;
	}
      } else {
	if (i < negs.size()-1 && j > 0 && negs[i]*negs[i+1] > poss[j]*poss[j-1]) {
	  ans = ans * negs[i] % mod * negs[i+1] % mod;
	  ans = ans * binpow(poss[--j], mod-2) % mod;
	  i += 2;
	} else {
	  ans = ans * poss[j++] % mod;
	}
	--k;
      }
    } else if (i < negs.size()-1) {
      if (k != 1) {
	ans = ans * negs[i] % mod * negs[i+1] % mod;
	i += 2;
	k -= 2;
      } else {
	ans = ans * negs[i] % mod * negs[i+1] % mod;
	ans = ans * binpow(poss[--j], mod-2) % mod;
	i += 2;
	--k;
      }
    } else {
      ans = ans * poss[j++] % mod;
      --k;
    }
  }
  printf("%lld", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
