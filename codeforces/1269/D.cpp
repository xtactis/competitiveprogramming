#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    long long ans[2] = {};
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ans[i%2] += x/2;
        ans[(i+1)%2] += (x+1)/2;
    }
    printf("%I64d", min(ans[0], ans[1]));
    return 0;
}