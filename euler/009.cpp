#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int a = 1; a < 1000; ++a) {
        for (int b = a+1; b < 1000; ++b) {
            int c = 1000-a-b;
            if (c == a || c == b) continue;
            if (a*a + b*b != c*c) continue;
            printf("%d", a*b*c);
            return 0;
        }
    }
    return 0;
}