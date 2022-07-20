#include <bits/stdc++.h>
using namespace std;

const int N = 321;
const long long inf = 1e17;

int n, m, l, q;

long long dist[N][N];

int main() {
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a; --b;
        dist[b][a] = dist[a][b] = c;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= l) dist[i][j] = 1;
            else dist[i][j] = inf;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    scanf("%d", &q);
    while (q--) {
        int s, t;
        scanf("%d %d", &s, &t);
        if (dist[s-1][t-1] >= inf) printf("-1\n");
        else printf("%lld\n", dist[s-1][t-1]-1);
    }
    return 0;
}