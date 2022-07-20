#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    for (int i = 1;; ++i) {
        ans += i;
        int cnt = 0;
        for (int j = 1; j * j <= ans; ++j) {
            if (ans % j) continue;
            ++cnt;
            if (ans / j != j) ++cnt;
        }
        if (cnt >= 500) {
            printf("%lld", ans);
            return 0;
        }
    }
    
    return 0;
}