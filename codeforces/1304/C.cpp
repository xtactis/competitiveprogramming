#include <bits/stdc++.h>
using namespace std;

const int N = 123;

vector<long long> T, L, H;

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        T.clear(); L.clear(); H.clear();
        int n, m; scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            long long t, l, h;
            scanf("%lld %lld %lld", &t, &l, &h);
            if (T.size() && t == T.back()) {
                L[L.size()-1] = max(L[L.size()-1], l);
                H[H.size()-1] = min(H[H.size()-1], h);
                continue;
            }
            T.push_back(t);
            L.push_back(l);
            H.push_back(h);
        }
        long long cl = m, ch = m, t = 0;
        bool ans = true;
        for (int i = 0; i < (int)T.size(); ++i) {
            const int d = T[i]-t;
            if (ch+d < L[i] || cl-d > H[i]) {
                // unreachable
                ans = false;
                break;
            }
            cl = cl+d <= L[i] ? L[i] : max(cl-d, L[i]);
            ch = ch-d >= H[i] ? H[i] : min(ch+d, H[i]);
            if (cl > ch) {
                ans = false;
                break;
            }
            t = T[i];
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}