#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int a[N];
pair<int, int> h2[2][N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        ++h2[i%2][a[i]].first;
        h2[i%2][a[i]].second = a[i];
    }
    sort(h2[0], h2[0]+N, greater<pair<int, int>>());
    sort(h2[1], h2[1]+N, greater<pair<int, int>>());
    int x, y;
    x = h2[0][0].second;
    y = h2[1][0].second;
    if (h2[0][0].second == h2[1][0].second) {
        if (h2[0][0].first + h2[1][1].first > h2[0][1].first + h2[1][0].first) {
            x = h2[0][0].second;
            y = h2[1][1].second;
        } else {
            x = h2[0][1].second;
            y = h2[1][0].second;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i%2 == 0 && a[i] != x) ++ans;
        if (i%2 == 1 && a[i] != y) ++ans;
    }
    printf("%d", ans);
    
    return 0;
}