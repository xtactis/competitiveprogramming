#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve() {
    string s; cin >> s;
    if (s.size() == 1) {
        cout << (stoi(s)%8?"No":"Yes");
        return;
    } else if (s.size() == 2) {
        string q(s.rbegin(), s.rend());
        cout << (stoi(s)%8?(stoi(q)%8?"No":"Yes"):"Yes");
        return;
    }
    int d[10] = {};
    for (char c: s) {
        ++d[c-'0'];
    }
    for (int i = 104; i < 1000; i += 8) {
        int t[10] = {}, c = i;
        while (c) {
            ++t[c%10];
            c /= 10;
        }
        int f = true;
        for (int j = 0; j < 10; ++j) {
            if (d[j] < t[j]) {
                f = false;
                break;
            }
        }
        if (!f) continue;
        cout << "Yes";
        return;
    }
    cout << "No";
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
