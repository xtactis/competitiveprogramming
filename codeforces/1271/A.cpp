#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long ans = 0;
    while (d > 0 && (a > 0 || (b > 0 && c > 0))) {
        if (e > f && a > 0) {
            while (min(a, d)) {
                --a; --d;
                ans += e;
            }
        } else if (e < f && b > 0 && c > 0) {
            while (min(b, min(c, d))) {
                --b; --d; --c;
                ans += f;
            }
        } else if (a > 0) {
            while (min(a, d)) {
                --a; --d;
                ans += e;
            }
        } else if (b > 0 && c > 0) {
            while (min(b, min(c, d))) {
                --b; --d; --c;
                ans += f;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}