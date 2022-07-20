#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, k, d;
    scanf("%lld%lld%lld", &x, &k, &d);
    x = abs(x);
    if (x/d >= k) {
        printf("%lld\n", x-d*k);
        return 0;
    }
    k -= x/d;
    x %= d;
    if (k&1) {
        x = d-x;
    }
    printf("%lld\n", x);
    
    return 0;
}