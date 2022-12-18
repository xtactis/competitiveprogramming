#include <bits/stdc++.h>

using namespace std;

int finda(const vector<long long> &pprimes, int x) {
    int ret = 0;
    for (int i = 1; i < pprimes.size(); ++i) {
        int lo = 0, hi = i;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (pprimes[i]-pprimes[mid] > x) lo = mid+1;
            else hi = mid;
        }
        if (pprimes[i]-pprimes[hi] == x && i-hi > ret) {
            ret = i-hi;
        }
    }
    return ret;
}

int main() {
    vector<int> primes;
    vector<long long> prefix_primes;
    primes.push_back(2);
    prefix_primes.push_back(2);
    int maxa = 0;
    int res = 0;
    for (int i = 3; i < 1000000; i += 2) {
        int lim = sqrt(i);
        bool isprime = true;
        for (int p: primes) {
            if (p > lim) break;
            if (i % p == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            primes.push_back(i);
            prefix_primes.push_back(prefix_primes.back() + i);
            int a = finda(prefix_primes, i);
            if (a > maxa) {
                maxa = a;
                res = i;
            }
        }
    }
    printf("%d\n", res);

    return 0;
}
