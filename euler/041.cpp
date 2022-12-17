#include <bits/stdc++.h>

using namespace std;

bool contains(long long x, int y) {
    while (x) {
        if (x % 10 == y) return true;
        x /= 10;
    }
    return false;
}

long long check(long long x, int n) {
    if (x % 2 == 0) return 0;
    for (int i = 1; i < n; ++i) {
        if (!contains(x, i)) return 0;
    }
    for (long long i = 3, root = sqrt(x); i <= root; i += 2) {
        if (x % i == 0) return 0;
    }
    return x;
}

long long dfs(long long c, int n = 1) {
    long long ret = check(c, n);
    if (n == 10) {
        return ret;
    }
    c *= 10;
    for (int i = 1; i < 10; ++i) {
        ret = max(ret, dfs(c+i, n+1));
    }
    return ret;
}

int main() {
    printf("%lld\n", dfs(0));

    return 0;
}
