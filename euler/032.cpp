#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9};
    set<int> s;
    do {
        int p = 0;
        for (int i = 5; i < 9; ++i) {
            p *= 10;
            p += a[i];
        }
        for (int i = 1; i < 4; ++i) {
            int f1 = 0, f2 = 0;
            for (int j = 0; j < i; ++j) {
                f1 *= 10;
                f1 += a[j];
            }
            for (int j = i; j < 5; ++j) {
                f2 *= 10;
                f2 += a[j];
            }
            if (f1*f2 == p) {
                s.insert(p);
                break;
            }
        }
    } while (next_permutation(a, a+9));
    int ans = 0;
    for (int e: s) {
        ans += e;
    }
    printf("%d", ans);
    return 0;
}