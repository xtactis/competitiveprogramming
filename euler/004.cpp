#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = -1;
    for (int i = 100; i < 1000; ++i) {
        for (int j = i; j < 1000; ++j) {
            int x = i * j;
            int top = x / 1000, bot = x % 1000;
            if (top / 100 == bot % 10 && (top % 100) / 10 == (bot / 10) % 10 && top % 10 == bot / 100) {
                ans = max(ans, x);
            }
        }
    }
    printf("%d", ans);
    return 0;
}