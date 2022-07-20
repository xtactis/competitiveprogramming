#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char c, pc = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &c);
        if (pc != c) {
            ++ans;
        }
        pc = c;
    }
    cout << ans;
    return 0;
}