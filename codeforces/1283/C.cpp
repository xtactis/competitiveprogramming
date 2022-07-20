#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+45;
int a[N];
int cnt[N];
vector<int> zeros;
set<int> ones;
set<int> negs;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        if (a[i] != 0) {
            ++cnt[a[i]];
            --cnt[i];
        }
        if (cnt[i] == 1) {
            ones.insert(i);
        }
        if (cnt[i] == -1) {
            negs.insert(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0 && cnt[i] == 0) {
            zeros.push_back(i);
        }
    }
    for (int i = 0; i < (int)zeros.size(); ++i) {
        a[zeros[i]] = *negs.begin();
        --cnt[zeros[i]];
        ++cnt[a[zeros[i]]];
        negs.erase(a[zeros[i]]);
        ones.erase(zeros[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != 0) continue;
        if (cnt[i] == 1) {
            a[i] = *negs.begin();
            --cnt[i];
            ++cnt[a[i]];
            negs.erase(a[i]);
            ones.erase(i);
        }
        if (cnt[i] == -1) {
            a[i] = *ones.begin();
            ++cnt[i];
            --cnt[a[i]];
            ones.erase(a[i]);
            negs.erase(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}