#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 1;
    for (int i = 1; i <= 1001/2; ++i) {
        ans += 4*(2*i+1)*(2*i+1) - 12*i;
    }
    printf("%lld", ans);
    return 0;
}