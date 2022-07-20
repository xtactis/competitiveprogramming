#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int tot = 0, twos = 0, ones = 0;
    for (auto &c: s) {
        c = (c-'0')%3;
        tot += c;
        if (c == 2) ++twos;
        else if (c == 1) ++ones;
    }
    tot %= 3;
    if (!tot) {
        cout << 0;
    } else if (tot == 1 && ones && s.size() > 1) {
        cout << 1;
    } else if (tot == 1 && twos > 1 && s.size() > 2) {
        cout << 2;
    } else if (tot == 2 && twos && s.size() > 1) {
        cout << 1;
    } else if (tot == 2 && ones > 1 && s.size() > 2) {
        cout << 2;
    } else {
        cout << -1;
    }
    return 0;
}