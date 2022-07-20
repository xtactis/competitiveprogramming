#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int m = (x-y+1)%(b+a);
        if ((x-y+1)%(b+a)) {
            cout << -1 << "\n";
        } else {
            cout << (x-y+1)/(b+a) << "\n";
        }
    }
    return 0;
}