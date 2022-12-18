#include <bits/stdc++.h>

using namespace std;

int main() {
    for (long long d = 1; ; ++d) {
        long long Pd = d*(3*d-1)/2;
        for (long long i = d+1; ; ++i) {
            long long Pi = i*(3*i-1)/2;
            long long Pjm = (i-1)*(3*(i-1)-1)/2;
            if (Pi-Pjm > Pd) break;
            long long lo = 1, hi = i;
            while (lo < hi) {
                long long mid = (hi+lo)/2;
                long long Pj = mid*(3*mid-1)/2;
                if (Pi-Pj > Pd) lo = mid+1;
                else hi = mid;
            }
            long long Pj = hi*(3*hi-1)/2;
            if (Pi-Pj == Pd) {
                long long Ps = Pj+Pi;
                //0 = 3*s^2-s-2*Ps
                long long s = (1+sqrt(1+4*3*2*Ps))/6;
                if (Ps == s*(3*s-1)/2) {
                    printf("%lld\n", Pd);
                    return 0;
                }
            }
        }
    }

    return 0;
}
