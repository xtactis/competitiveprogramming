#include <bits/stdc++.h>
using namespace std;

int v[] = {1, 2, 5, 10, 20, 50, 100, 200};

int calc(int i, int rem) {
    if (i == 0) return 1;
    int ret = 0;
    for (int j = 0, lmt = rem/v[i]; j <= lmt; ++j) {
        ret += calc(i-1, rem-v[i]*j);
    }
    return ret;
}

int main() {
    printf("%lld", calc(sizeof(v)/4, 200));
    return 0;
}