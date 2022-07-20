#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+23;

int a[N];
int n, q;

int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r+1))-1) {
        ret ^= a[r];
    }
    return ret;
}

int sum(int l, int r) {
    return sum(r) ^ sum(l-1);
}

void add(int idx, int delta) {
    for (; idx < n; idx |= idx+1) {
        a[idx] ^= delta;
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        add(i, x);
    }
    while (q--) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            add(x-1, y);
        } else {
            printf("%d\n", sum(x-1, y-1));
        }
    }
}