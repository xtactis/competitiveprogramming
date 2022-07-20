#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    for (int i = 3; i < 1000; ++i) {
        if (i % 3 && i % 5) continue;
        ans += i;
    }
    printf("%lld", ans);
    return 0;
}