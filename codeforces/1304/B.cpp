#include <bits/stdc++.h>
using namespace std;

map<string, bool> m;
set<string> p;

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, z; cin >> n >> z;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        string r(x.rbegin(), x.rend());
        if (x == r) {
            p.insert(x);
        } else if (m.find(r) != m.end()) {
            m[r] = 1;
            m[x] = 1;
        } else {
            m[x] = 0;
        }
    }
    string front = "", back = "";
    for (const auto &e: m) {
        if (!e.second) continue;
        front += e.first;
        m[e.first] = 0;
        string r(e.first.rbegin(), e.first.rend());
        back = r+back;
        m[r] = 0;
    }
    cout << front.size()+(*p.begin()).size()+back.size() << endl;
    cout << front << *p.begin() << back << endl;
    
    return 0;
}