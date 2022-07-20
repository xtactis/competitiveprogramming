#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> koef;

long long count(long long x, long long koef=2) {
    if (koef*x > n) return 0;
    if (koef*x+koef-1 <= n) {
        return koef+count(x, 2*koef);
    }
    return n-koef*x+1;
}

int main() {
    cin >> n >> k;
    if (n == k) return !printf("1");
    if (k == 1) return !printf("%I64d", n);
    // bin even
    long long lo = 1, hi = n/2+1;
    while (lo+1<hi) {
        long long mid = lo+(hi-lo)/2;
        long long x = mid*2;
        if (2+count(x)+count(x+1) >= k) lo = mid;
        else hi = mid;
    }
    long long ansEven = lo*2;
    // bin odd
    lo = 1, hi = n/2+1;
    while (lo+1<hi) {
        long long mid = lo+(hi-lo)/2;
        long long x = mid*2-1;
        if (1+count(x) >= k) lo = mid;
        else hi = mid;
    }
    long long ansOdd = lo*2-1;
    cout << max(ansEven, ansOdd) << endl;
    return 0;
}