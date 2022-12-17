#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    for (string line; getline(cin, line, ',');) {
        int value = 0;
        for (char c: line) {
            if (c == '"') continue;
            value += c-'A'+1;
        }
        int n = (sqrt(1+8*value)-1)/2;
        if (n*(n+1)/2 == value) ++ans;
    }
    printf("%d", ans);

    return 0;
}
