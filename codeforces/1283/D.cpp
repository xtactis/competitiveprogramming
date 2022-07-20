#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

set<int> trees;
set<int> pos;
priority_queue<pair<int, int>> opt;
vector<int> ans;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        trees.insert(a);
    }
    for (int e: trees) {
        if (!trees.count(e-1) && !pos.count(e-1)) {
            pos.insert(e-1);
            opt.emplace(-1, e-1);
        }
        if (!trees.count(e+1) && !pos.count(e+1)) {
            pos.insert(e+1);
            opt.emplace(-1, e+1);
        }
    }
    long long res = 0;
    for (int i = 0; i < m; ++i) {
        pair<int, int> e = opt.top();
        opt.pop();
        res += -e.first;
        ans.push_back(e.second);
        if (!trees.count(e.second-1) && !pos.count(e.second-1)) {
            pos.insert(e.second-1);
            opt.emplace(-(1+-e.first), e.second-1);
        }
        if (!trees.count(e.second+1) && !pos.count(e.second+1)) {
            pos.insert(e.second+1);
            opt.emplace(-(1+-e.first), e.second+1);
        }
    }
    printf("%I64d\n", res);
    for (int e: ans) {
        printf("%d ", e);
    }
    return 0;
}