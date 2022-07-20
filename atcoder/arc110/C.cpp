#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+23;

int p[N], ind[N];
bool used[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", p+i);
        ind[p[i]] = i+1;
    }
    vector<int> ans;
    for (int i = n; i > 1; --i) {
        for (int j = ind[i]; j < i; ++j) {
            if (used[j]) {
                printf("-1");
                return 0;
            }
            used[j] = true;
            ans.push_back(j);
            --ind[j+1];
        }
        ind[i] = i;
    }
    if (ans.size() != n-1) {
        printf("-1");
        return 0;
    }
    for (int e: ans) {
        printf("%d\n", e);
    }
}