#include <bits/stdc++.h>
using namespace std;

int n, sx, sy;

int main() {
    scanf("%d %d %d", &n, &sx, &sy);
    int up = 0, down = 0, left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (v > sy) ++up;
        if (v < sy) ++down;
        if (u > sx) ++right;
        if (u < sx) ++left;
    }
    if (up >= down && up >= right && up >= left) return !printf("%d\n%d %d", up, sx, sy+1);
    if (down >= up && down >= right && down >= left) return !printf("%d\n%d %d", down, sx, sy-1);
    if (left >= down && left >= right && left >= up) return !printf("%d\n%d %d", left, sx-1, sy);
    if (right >= down && right >= left && right >= up) return !printf("%d\n%d %d", right, sx+1, sy);
    
    return 0;
}