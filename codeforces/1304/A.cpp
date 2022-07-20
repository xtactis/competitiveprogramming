#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if ((y-x)%(b+a)) {
            cout << -1 << "\n";
        } else {
            cout << (y-x)/(b+a) << "\n";
        }
    }
    return 0;
}