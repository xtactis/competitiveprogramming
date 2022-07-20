#include <bits/stdc++.h>
using namespace std;

int d(int n) {
    int ret = 0;
    for (int i = 1; i*i <= n; ++i) {
        if (n % i) continue;
        ret += i;
        if (i != 1 && n/i != i) ret += n/i;
    }
    return ret;
}

bool can[28124];

int main() {
    vector<int> abundant;
    for (int i = 1; i <= 28123; ++i) {
        if (d(i) > i) abundant.push_back(i);
    }
    for (int e: abundant) {
        for (int f: abundant) {
            if (e+f > 28123) continue;
            can[e+f] = true;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 28123; ++i) {
        if (!can[i]) ans += i;
    }
    printf("%lld", ans);
    return 0;
}