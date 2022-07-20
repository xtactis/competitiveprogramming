#include <bits/stdc++.h>
using namespace std;

const int N = 30;

string s[N];
string t[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    int q; cin >> q;
    while (q--) {
        int y; cin >> y;
        cout << s[(y-1)%n] << t[(y-1)%m] << endl;
    }
    return 0;
}