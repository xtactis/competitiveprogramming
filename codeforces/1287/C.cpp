#include <bits/stdc++.h>
using namespace std;

const int N = 123;

int n; 
int a[N];

int dp[2][N][N][N];
int rec(int par, int pos, int ev, int od) {
    if (ev < 0 || od < 0) return 1e9;
    if (pos == n) return 0;
    if (dp[par][pos][ev][od] != -1) return dp[par][pos][ev][od];
    if (a[pos] != 0) {
        return dp[par][pos][ev][od] = rec(a[pos]%2, pos+1, ev, od)+(a[pos]%2!=par);
    }
    if (pos == 0) {
        return dp[par][pos][ev][od] = min(rec(1, pos+1, ev, od-1), rec(0, pos+1, ev-1, od));
    }
    return dp[par][pos][ev][od] = min(rec(1, pos+1, ev, od-1)+(par!=1), rec(0, pos+1, ev-1, od)+(par!=0));
}

int main() {
    cin >> n;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k) for (int l = 0; l < n; ++l)
            dp[i][j][k][l] = -1;
    int parity[2] = {n/2, (n+1)/2};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) --parity[a[i]%2];
    }
    cout << rec(a[0]%2, 0, parity[0], parity[1]);
    return 0;
}