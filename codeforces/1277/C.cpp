#include <bits/stdc++.h>
using namespace std;
set<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        //twone
        for (int i = 0; i < (int)s.size()-4; ++i) {
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e') {
                ans.insert(i+2);
                i += 4;
                continue;
            }
        }
        for (int i = 0; i < (int)s.size()-2; ++i) {
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && ans.count(i+2)) {
                i += 4;
                continue;
            }
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
                ans.insert(i+1);
                i += 2;
                continue;
            }
            if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
                ans.insert(i+1);
                i += 2;
                continue;
            }
        }
        cout << ans.size() << "\n";
        for (int e: ans) {
            cout << e+1 << ' ';
        }
        cout << "\n";
        ans.clear();
    }
    return 0;
}