#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;

pair<int, int> a[N];
vector<pair<int, int>> ans;
int h[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i+1;
    }
    sort(a, a+n);
    if (a[1].first == 0 || a[0].first != 0) return !printf("-1");
    int cur = -1, cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (cnt == 0) ++cur;
        if (a[i].first - a[cur].first > 2) {
            return !printf("-1");
        } else if (a[i].first - a[cur].first == 2) {
            while (a[i].first - a[cur].first == 2) ++cur;
            cnt = 0;
        }
        if (a[i].first - a[cur].first == 0) {
            return !printf("-1");
        }
        if (++h[cur] > k) {
            ++cur; --i;
            continue;
        }
        if (++h[i] > k) {
            continue;
        }
        ans.emplace_back(a[cur].second, a[i].second);
        cnt = (cnt+1)%k;
    }
    printf("%d\n", (int)ans.size());
    for (const auto &e: ans) {
        printf("%d %d\n", e.first, e.second);
    }
    return 0;
}
