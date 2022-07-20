#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[60];
    unsigned long long ans = 0;
    for (int i = 0; i < 100; ++i) {
        scanf(" %s", s);
        long long cur = 0;
        for (int j = 0; j < 17; ++j) {
            cur *= 10;
            cur += s[j]-'0';
        }
        ans += cur;
    }
    printf("%llu", ans);
    return 0;
}