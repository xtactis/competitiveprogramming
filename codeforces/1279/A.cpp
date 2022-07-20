#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int r, g, b; scanf("%d %d %d", &r, &g, &b);
        int x[3] = {r, g, b};
        sort(x, x+3);
        r = x[2]; g = x[1]; b = x[0];
        if (r-g <= 1 && g-b <= 1 && r-b <= 1) puts("Yes");
        else if (r-g <= 1) puts("Yes");
        else if (r-(g+b) <= 1) puts("Yes");
        else puts("No");
    }
    
    return 0;
}