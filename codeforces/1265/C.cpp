#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+5;
const int M = 1e6+1;

int p[N];
int h[M];
int b[N];
vector<int> q;

bool check(int m, bool print=false) {
    bool ret = false;
    int i = lower_bound(b, b+q.size(), m)-b;
    if (i < 3)
    if (print) {
        if (ret) {
            
        } else {
            printf("0 0 0\n");
        }
    }
    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", p+i);
            ++h[p[i]];
            if (!q.size() || q.back() != p[i]) q.push_back(p[i]);
        }
        for (int i = 0; i < (int)q.size(); ++i) {
            b[i] = p[q[i]];
            if (i > 0) b[i] += b[i-1];
        }
        int lo = -1, hi = n/2+1;
        while (lo+1 < hi) {
            int mid = lo+(hi-lo)/2;
            if (check(mid)) lo = mid;
            else hi = mid;
        }
        check(lo, true);
        q.clear();
    }
    return 0;
}
