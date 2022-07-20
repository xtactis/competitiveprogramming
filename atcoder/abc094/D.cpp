#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int N = 1e5+23;
int a[N];

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    sort(a, a+n);
    int m = a[n-1];
    printf("%d ", m);
    auto p = equal_range(a, a+n-1, m/2);
    if (*(p.first) != m/2) --p.first;
    if (p.second == a+n-1 || abs(*(p.first)-m/2) < abs(*(p.second)-m/2)) {
        printf("%d", *(p.first));
    } else {
        printf("%d", *(p.second));
    }
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}