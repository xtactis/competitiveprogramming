#include <bits/stdc++.h>
using namespace std;

long long C[213][12];

int main() {
    int n; scanf("%d", &n);
    C[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < 12; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    printf("%lld", C[n-1][11]);
    return 0;
}