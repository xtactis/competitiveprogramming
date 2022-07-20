#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

int a[4];
int dp[N][4];

bool allzero() {
    return a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0;
}

bool dfs(int x) {
    if (x < 0 || x > 3) return false;
    if (dp[a[x]][x] != -1) return dp[a[x]][x];
    bool ret = false;
    if (a[x] > 0) {
        --a[x];
        ret = dfs(x+1) || dfs(x-1);
        ++a[x];
    } else {
        ret = allzero();
    }
    
    return (dp[a[x]][x] = ret);
}

vector<int> ans;
void print(int x) {
    if (allzero()) return;
    ans.push_back(x);
    if (a[x] > 0) {
        --a[x];
        if (dfs(x+1)) {
            print(x+1);
        } else if (dfs(x-1)) {
            print(x-1);
        }
    }
}

int main() {
    int n = 4;
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    //dfs(3);
    //return 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) for (int j = 0; j < N; ++j) dp[j][k] = -1;
        if (dfs(i)) {
            print(i);
            if (!ans.size()) continue;
            printf("YES\n");
            for (int e: ans) {
                printf("%d ", e);
            }
            return 0;
        }
    }
    printf("NO");
    return 0;
}
