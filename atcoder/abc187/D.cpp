#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+23;

long long a[N], b[N];
int ind[N];
long long S[N], A[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", a+i, b+i);
        ind[i] = i;
    }
    sort(ind, ind+n, [](int x, int y) {
             if (2*a[x]+b[x] == 2*a[y]+b[y]) return a[x] > a[y];
             return 2*a[x]+b[x] > 2*a[y]+b[y];
         });
    for (int i = 0; i < n; ++i) {
        S[i] = a[ind[i]]+b[ind[i]];
        A[i] = a[ind[i]];
        if (i) {
            S[i] += S[i-1];
            A[i] += A[i-1];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (S[i] > A[n-1]-A[i]) {
            printf("%d", i+1);
            return 0;
        }
    }
    
    return 0;
}