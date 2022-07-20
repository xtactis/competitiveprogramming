#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> mins, maxs_unsorted, maxs;

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int l; scanf("%d", &l);
        int mn = 2e9;
        int mx = -1;
        bool containAnyway = false;
        for (int j = 0; j < l; ++j) {
            int x; scanf("%d", &x);
            if (!containAnyway && x > mn && mn != -1) {
                containAnyway = true;
                ans += 2*(n-cnt++)-1;
            }
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if (containAnyway) continue;
        mins.push_back(mn);
        maxs.push_back(mx);
        maxs_unsorted.push_back(mx);
    }
    sort(maxs.begin(), maxs.end());
    int m = mins.size();
    for (int i = 0; i < m; ++i) {
        int lo = -1, hi = m;
        while (lo+1<hi) {
            int mid = lo+(hi-lo)/2;
            if (maxs[mid] <= mins[i]) lo = mid;
            else hi = mid;
        }
        ans += m-hi;
    }
    printf("%lld", ans);
    return 0;
}