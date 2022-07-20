#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+1;

string s;
vector<int> g[N];
int a[N];

bool bio[N];
int dfs(int u) {
    if (bio[u]) return a[u];
    bio[u] = true;
    for (int v: g[u]) {
        a[u] = max(a[u], 1+dfs(v));
    }
    return a[u];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int n = s.size()+1;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == '>') {
            g[i].push_back(i+1);
        } else {
            g[i+1].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() < 2 && i != 0 && i != n-1) continue;
        if ((i == 0 || i == n-1) && g[i].size() == 0) continue;
        dfs(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i];
    }
    cout << ans << endl;
    
    return 0;
}
