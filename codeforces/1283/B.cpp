#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);
        if (n%k == 0) {
            // 0 a+1 kids
            printf("%d\n", n);
        } else {
            // n%k a+1 kids
            if (n%k <= k/2) {
                printf("%d\n", n);
            } else {
                printf("%d\n", n-(n%k-k/2));
            }
        }
    }
    return 0;
}