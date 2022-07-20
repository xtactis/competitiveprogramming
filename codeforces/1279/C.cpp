#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int a[N], b[N];
set<int> B;
map<int, int> ans;

void clear() {
    B.clear();
    ans.clear();
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", b+i);
            B.insert(b[i]);
        }
        int wheredidIgetbro = 0;
        int forfree = 0;
        for (int i = 0; i < m; ++i) {
            if (ans.find(b[i]) != ans.end()) {
                ++forfree;
                continue;
            }
            for (int j = wheredidIgetbro; j < n; ++j) {
                if (a[j] == b[i]) {
                    B.erase(b[i]);
                    ans[b[i]] = (j-forfree)*2+1;
                    ++forfree;
                    wheredidIgetbro = j;
                    break;
                }
                if (B.count(a[j])) ans[a[j]] = 1;
            }
        }
        long long s = 0;
        for (const auto &e: ans) {
            s += e.second;
        }
        printf("%I64d\n", s);
        clear();
    }
    return 0;
}