#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;

int a[N];
map<int, int> m;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
            m[a[i]]++;
        }
        sort(a, a+n, greater<int>());
        int ans = 0;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            int e = it->first;
            if (e % 2 == 1) continue;
            m[e/2] += m[e];
            m[e] = 0;
            ++ans;
        }
        printf("%d\n", ans);
        m.clear();
    }
    return 0;
}