#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int checkall() {
    for (int i = 0; i < n-1; ++i) {
        if (s[i] != s[i+1]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    vector<int> ans;
    char col[] = {'W', 'B'};
    for (int c = 0; c < 2; ++c) {
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == col[c]) continue;
            s[i] = col[c];
            s[i+1] = s[i+1] == 'W'?'B':'W';
            ans.push_back(i);
        }
        if (checkall()) {
            cout << ans.size() << endl;
            for (int e: ans) {
                cout << e+1 << ' ';
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}