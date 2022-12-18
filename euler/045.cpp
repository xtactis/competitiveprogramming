#include <bits/stdc++.h>

using namespace std;

int main() {
    for (long long i = 286; ; ++i) {
        long long Ti = i*(i+1)/2;
        long long n = (1+sqrt(1+4*3*2*Ti))/6;
        long long Pi = n*(3*n-1)/2;
        //n(2n−1) = x -> 0 = 2n^2-n-x
        long long m = (1+sqrt(1+4*2*Ti))/4;
        long long Hi = m*(2*m-1);
        if (Ti != Pi || Ti != Hi) continue;
        printf("%lld\n", Ti);
        break;
    }
    return 0;
}
