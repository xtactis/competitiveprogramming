#include <bits/stdc++.h>
using namespace std;

const int N = 7004;

int n; 
vector<int> p[2];

int dp[2][N];
bool bio[2][N];
int rec(int move, int pos) {
    if (pos == 0) return -1;
    if (dp[move][pos] != -2) return dp[move][pos];
    if (move == origmove && pos == origpos) {
        printf("bruh %d %d %d %d", move, pos, origmove, origpos);
        return dp[move][pos] = 0;
    }
    if (origmove == -1) {
        origmove = move;
        origpos = pos;
    }
    int ret = -1;
    for (int e: p[move]) {
        ret = max(ret, -rec(!move, (pos+e)%n, origmove, origpos));
    }
    return dp[move][pos] = ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -2;
        }
    }
    for (int i = 0; i < 2; ++i) {
        int x; scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            int t; scanf("%d", &t);
            p[i].push_back(t);
        }
    }
    for (int move = 0; move < 2; ++move) {
        for (int pos = 1; pos < n; ++pos) {
            int ans = rec(move, pos);
            if (ans > 0) printf("Win ");
            else if (ans < 0) printf("Lose ");
            else printf("Loop ");
        }
        puts("");
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", dp[i][j]);
        }
        puts("");
    }
    
    return 0;
}