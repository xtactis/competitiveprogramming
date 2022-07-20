#include <bits/stdc++.h>
using namespace std;

const char *vowels = "aeiou";

int main() {
    int k; scanf("%d", &k);
    if (k < 25) return !printf("-1");
    for (int m = 5; m*m <= k; ++m) {
        int n = k/m;
        if (n >= 5 && n*m == k) {
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < m+i; ++j) {
                    putchar(vowels[(i*m+j)%5]);
                }
            }
            return 0;
        }
    }
    return !printf("-1");
}