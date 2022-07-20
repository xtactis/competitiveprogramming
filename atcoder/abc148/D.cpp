#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    int ans = 0;
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != cur) ++ans;
        else ++cur;
    }
    if (cur == 1) return !printf("-1");
    printf("%d", ans);
    return 0;
}