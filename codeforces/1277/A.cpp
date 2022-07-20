#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void dfs(long long x) {
    if (x > (long long)1e9) return;
    if (x != 0) {
        v.push_back(x);
    }
    dfs(x*10+x%10);
}

int main() {
    for (int i = 1; i < 10; ++i) dfs(i);
    sort(v.begin(), v.end());
    //for (int i = 0; i < 10; ++i) printf("%d ", v[i]);
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        printf("%d\n", (int)(upper_bound(v.begin(), v.end(), n)-v.begin()));
    }
    
    return 0;
}