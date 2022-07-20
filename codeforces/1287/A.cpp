#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 1; scanf("%d", &t);
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string q = s;
        for (int i = 0; i < n; ++i) {
            s = q;
            bool yep = false;
            for (int j = 0; j < n-1; ++j) {
                if (s[j] == 'A') {
                    if (q[j+1] == 'P') yep = true;
                    q[j+1] = 'A';
                }
            }
            if (!yep) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}