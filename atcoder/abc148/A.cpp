#include <bits/stdc++.h>
using namespace std;

int h[4];

int main() {
    int a, b; cin >> a >> b;
    h[a] = 1;
    h[b] = 1;
    for (int i = 1; i < 4; ++i) {
        if (!h[i]) return !printf("%d", i);
    }
    return 0;
}