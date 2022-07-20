#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;

int a[N], b[N];
//~ int a;
//~ int x, y, z;
int n, m, k;
//~ int b, c, d;

bool check() {
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) return false;
        if (a[i] < b[i]) return true;
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        char c; scanf(" %c", &c);
        a[i] = c-'0';
        b[i] = a[i];
    }
    for (int i = k; i < n; ++i) {
        b[i] = b[i-k];
    }
    printf("%d\n", n);
    if (!check()) {
        for (int i = k-1; i >= 0; --i) {
            b[i] = (b[i]+1)%10;
            if (b[i]) break;
        }
        for (int i = k; i < n; ++i) {
            b[i] = b[i-k];
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", b[i]);
    }
    return 0;
}