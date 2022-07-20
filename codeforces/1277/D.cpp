#include <bits/stdc++.h>
using namespace std;

int v[2][2];
vector<string> ss;

void clear() {
    v[0][0] = 0;
    v[0][1] = 0;
    v[1][0] = 0;
    v[1][1] = 0;
    ss.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cout << "\n";
        clear();
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            ++v[s[0]-'0'][s.back()-'0'];
            ss.push_back(s);
        }
        int ans = 0;
        int x = v[0][1];
        int y = v[1][0];
        if (x == 0 && y == 0) {
            if (v[0][0] == 0 && v[1][1] > 0) {
                cout << "0";
            } else if (v[1][1] == 0 && v[0][0] > 0) {
                cout << "0";
            } else {
                cout << "-1";
            }
            continue;
        }
        if (x > y) while (x > y) {
            --x;
            ++y;
            ++ans;
        } else if (y > x) while (y > x) {
            --y;
            ++x;
            ++ans;
        }
        if (x == 0) {
            if (y > 1) cout << "-1";
            else cout << "0";
            continue;
        }
        if (y == 0) {
            if (x > 1) cout << "-1";
            else cout << "0";
            continue;
        }
        if (x != y) {
            cout << "-1";
            continue;
        }
        cout << ans << endl;
        for (int i = 0; i < (int)ss.size() && ans; ++i) {
            if (x < v[0][1]) {
                if (ss[i][0] == '0' && ss[i].back() == '1') {
                    cout << i+1 << ' ';
                    --ans;
                }
            }
            if (y < v[1][0]) {
                if (ss[i].back() == '0' && ss[i][0] == '1') {
                    cout << i+1 << ' ';
                    --ans;
                }
            }
        }
    }
    return 0;
}