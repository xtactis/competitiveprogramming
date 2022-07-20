#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int main() {
    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += i * i;
    }
    printf("%lld", (N*(N+1)/2)*(N*(N+1)/2) - sum);
    return 0;
}