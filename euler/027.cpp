#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    if (x <= 1) return false;
    if (x%2 == 0) return false;
    for (int i = 3; i*i <= x; i += 2) {
        if (x%i) continue;
        return false;
    }
    return true;
}

int main() {
    int ans = 0, mans = 0;
    for (int i = -999; i < 1000; ++i) {
        for (int j = -1000; j <= 1000; ++j) {
            for (int n = 0; ; ++n) {
                if (!check(n*n+i*n+j)) {
                    if (n > mans) {
                        mans = n;
                        ans = i*j;
                    }
                    break;
                }
            }
        }
    }
    printf("%d", ans);
}