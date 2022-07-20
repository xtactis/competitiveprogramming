#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool f = true;
        for (int j = 0; j < (int)s.size(); ++j) {
            if (s[j] != '?' && j > 0 && s[j] == s[j-1]) {
                f = false;
                break;
            } else if (s[j] != '?') continue;
            set<char> q; q.insert('a'); q.insert('b'); q.insert('c');
            if (j > 0 && s[j-1] != '?') q.erase(s[j-1]);
            if (j < (int)s.size()-1 && s[j+1] != '?') q.erase(s[j+1]);
            s[j] = *q.begin();            
        }
        if (f) {
            cout <<  s << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
