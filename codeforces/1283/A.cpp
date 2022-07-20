#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int h, m; scanf("%d %d", &h, &m);
        printf("%d\n", 60*(23-h)+60-m);
    }
    return 0;
}