#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

char ans[1003][1003];

string s3[3] = {"aab", "d.b", "dcc"};
string s4[4] = {"abcc", "abdd", "ccab", "ddab"};
string s5[5] = {"abbcc", "ajj.d", "h..kd", "h..ke", "ggffe"};
string s6[6] = {"aabaa.", "d.b..b", "dcc..b", "aa.aac", "..cd.c", "..cdbb"};
string s7[7] = {".xxyyzz", "xaa.aa.", "x..b..b", "y..b..b", "yaa.aa.", "z..b..b", "z..b..b"};

int n;

void filln(int from, int to, int n, string s[]) {
    for (int i = from; i < to; ++i) {
        for (int j = from; j < to; ++j) {
            ans[i][j] = s[(i-from)%n][(j-from)%n];
        }
    }
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j]) putchar(ans[i][j]);
            else putchar('.');
        }
        puts("");
    }
    exit(0);
}

int main() {
    scanf("%d", &n);
    int x = n;
    int prev = n;
    if (n < 3) {
        puts("-1");
        return 0;
    }
    if (n%5 == 0) {
        while (x) {
            x -= 5;
            filln(x, prev, 5, s5);
            prev = x;
        }
    } else if (n == 7) {
        filln(0, 7, 7, s7);
    } else if (n == 11) {
        filln(0, 6, 6, s6);
        filln(6, 11, 5, s5);
    } else if (n%3==0) {
        while (x) {
            x -= 3;
            filln(x, prev, 3, s3);
            prev = x;
        }
    } else {
        while (x%4 != 0 && x > 0) {
            x -= 5;
            filln(x, prev, 5, s5);
            prev = x;
        }
        while (x) {
            x -= 4;
            filln(x, prev, 4, s4);
            prev = x;
        }
    }
    print();
    
    return 0;
}