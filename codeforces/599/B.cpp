#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

int f[N], a[N], b[N];
vector<int> fi[N];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", f+i);
        --f[i];
        fi[f[i]].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", b+i);
        --b[i];
        if (fi[b[i]].size() == 0) {
            return !printf("Impossible");
        }
    }
    for (int i = 0; i < m; ++i) {
        if (fi[b[i]].size() > 1) {
            return !printf("Ambiguity");
        }
        a[i] = fi[b[i]][0];
    }
    puts("Possible");
    for (int i = 0; i < m; ++i) {
        printf("%d ", a[i]+1);
    }
    return 0;
}