#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    int ans = 0;
    int n = (int)s.size();
    for (int i = 0; i < n/2; ++i) {
        ans += s[i] != s[n-i-1];
    }
    cout << ans;
    
    return 0;
}
