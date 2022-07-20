#include <bits/stdc++.h>
using namespace std;

#define checkprint(x, y) if((x)*j == (y)*i) printf("%d/%d = %d/%d\n", i, j, (x), (y)), num *= x, den *= y;

int main() {
    int ans = 1, num = 1, den = 1;
    for (int i = 11; i < 100; ++i) {
        for (int j = i+1; j < 100; ++j) {
            if (i%10 == 0 && j%10 == 0) continue;
            int a1 = i%10, a2 = i/10;
            int b1 = j%10, b2 = j/10;
            if (a1 == b1) {
                checkprint(a2, b2);
            } else if (a1 == b2) {
                checkprint(a2, b1);
            } else if (a2 == b1) {
                checkprint(a1, b2);
            } else if (a2 == b2) {
                checkprint(a1, b1);
            }
        }
    }
    printf("%d", den/__gcd(num, den));
    return 0;
}