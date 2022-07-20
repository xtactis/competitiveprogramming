#include <bits/stdc++.h>
using namespace std;

// doesn't work for
// 5
// 4 3 2 2 1

const int N = 3e5+2;
 
int a[N], b[N];
//~ int a;
//~ int x, y, z;
int n, m, l;
//~ int b, c, d;
 
int main() {
    scanf("%d", &n);
    int j = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        if (i > 0) {
            int cur = a[i-1];
            while (a[i] < cur--) {
                b[j++] = cnt;
            }
        }
        ++cnt;
    }
    int cur = a[n-1];
    while (cur-- > 0) {
        b[j++] = n;
    }
    sort(b, b+j, greater<int>());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) {
            ans += a[i]/2;
            a[i] %= 2;
        }
        if (a[i] != 1 || i == 0 || a[i-1] != 1) continue;
        a[i] = a[i-1] = 0;
        ++ans;
    }
    long long ans2 = 0;
    for (int i = 0; i < j; ++i) {
        //cout << b[i] << ' ';
        if (b[i] > 1) {
            ans2 += b[i]/2;
            b[i] %= 2;
        }
        if (b[i] != 1 || i == 0 || b[i-1] != 1) continue;
        b[i] = b[i-1] = 0;
        ++ans2;
    }
    cout << ans << ' ' << ans2 << endl;
    printf("%lld", max(ans, ans2));
    return 0;
}