#include <bits/stdc++.h>
using namespace std;

const int N = 123;

int n, k; 
char s[N]; 
char dp[N][N][N];

int binpow(int b, int e) {
    if (!e) return 1;
    if (e&1) return b*binpow(b, e-1)%n;
    return binpow(b*b%n, e/2);
}

char rek(int pos, int exp) {
    if (!exp) return s[pos];
    int e = binpow(2, exp-1);
    char &ret = dp[pos][(pos+e)%n][exp];
    if (ret != -1) return ret;
    char a = rek(pos, exp-1);
    char b = rek((pos+e)%n, exp-1);
    ret = a;
    if (a == 'R' && b == 'P') {
        ret = b;
    } else if (a == 'P' && b == 'S') {
        ret = b;
    } else if (a == 'S' && b == 'R') {
        ret = b;
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf(" %d%d%s", &n, &k, s);
    printf("%c", rek(0, k));
    return 0;
}