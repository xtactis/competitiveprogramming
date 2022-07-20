#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

long long calc(long long a, long long b) {
    if (a%2 == b%2) {
        return (b-a)/2;
    } else if (b-a == 1) {
        return b-1;
    } else {
        long long x = b-a;
        return a-!(x&1)+x/2;
    }
}

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    cout << min(calc(a, b), calc(n-b+1, n-a+1));
    
    return 0;
}