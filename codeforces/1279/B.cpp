#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int a[N];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, s; scanf("%d %d", &n, &s);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
        }
        long long sum = 0;
        int m = 0, ind = -1;
        bool broke = false;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (m < a[i]) {
                m = a[i];
                ind = i;
            }
            if ((sum + a[i]) > s) {
                broke = true;
                break;
            }
            sum += a[i];
            ++cnt;
        }
        if (!broke) {
            puts("0");
            continue;
        }
        long long newsum = 0;
        broke = false;
        //cout << m << endl;
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == m) continue;
            if ((newsum + a[i]) > s) {
                if (cnt2 <= cnt) puts("0");
                else printf("%d\n", ind+1);
                broke = true;
                break;
            }
            newsum += a[i];
            ++cnt2;
        }
        if (!broke) {
            if (cnt2 <= cnt) puts("0");
            else printf("%d\n", ind+1);
        }
    }
    
    return 0;
}