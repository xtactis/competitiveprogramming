#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;
vector<string> ss;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    ss.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> ss[i];
        s.insert(ss[i]);
    }
    long long ans = 0;
    int c[30] = {0};
    c['S'-'A'] = 1;
    c['E'-'A'] = 1;
    c['T'-'A'] = 1;
    string f(k, 'S');
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int l = 0; l < k; ++l) {
                if (ss[i][l] == ss[j][l]) {
                    f[l] = ss[i][l];
                } else {
                    --c[ss[i][l]-'A'];
                    --c[ss[j][l]-'A'];
                    if (c['S'-'A']) f[l] = 'S';
                    if (c['E'-'A']) f[l] = 'E';
                    if (c['T'-'A']) f[l] = 'T';
                    ++c[ss[i][l]-'A'];
                    ++c[ss[j][l]-'A'];
                }
            }
            ans += s.count(f);
        }
    }
    cout << ans/3;
    return 0;
}