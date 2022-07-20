#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+2;

int a[N], b[N];

long long good(queue<int> in) {
    int n = in.front(); in.pop();
    //cout << n << endl;
    long long ans[2] = {};
    for (int i = 0; i < n; ++i) {
        int x = in.front(); in.pop();
        //cout << x << ' ';
        ans[i%2] += x/2;
        ans[(i+1)%2] += (x+1)/2;
    }
    return min(ans[0], ans[1]);
}

 
long long bad(queue<int> in) {
    int n = in.front(); in.pop();
    int j = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = in.front(); in.pop();
        if (i > 0) {
            int cur = a[i-1];
            while (a[i] < cur--) {
                b[j++] = cnt;
            }
        }
        ++cnt;
    }
    int cur = a[n-1];
    while (cur-- > 0) {
        b[j++] = n;
    }
    sort(b, b+j, greater<int>());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) {
            ans += a[i]/2;
            a[i] %= 2;
        }
        if (a[i] != 1 || i == 0 || a[i-1] != 1) continue;
        a[i] = a[i-1] = 0;
        ++ans;
    }
    long long ans2 = 0;
    for (int i = 0; i < j; ++i) {
        if (b[i] > 1) {
            ans2 += b[i]/2;
            b[i] %= 2;
        }
        if (b[i] != 1 || i == 0 || b[i-1] != 1) continue;
        b[i] = b[i-1] = 0;
        ++ans2;
    }
    return max(ans, ans2);
}

long long binpow(long long b, long long e) {
    if (!e) return 1;
    if (e%2) return b*binpow(b, e-1);
    return binpow(b*b, e/2);
}

int main() {
    queue<int> in;
    int n;
    scanf("%d", &n);
    for (long long k = 0; k < binpow(n, n); ++k) {
        in.push(n);
        //cout << n << endl;
        long long x = k;
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) {
            v[i] = x%n;
            x /= n;
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int e: v) {
            //cout << e+1 << ' ';
            in.push(e+1);
        }
        //puts("");
        auto G = good(in);
        auto B = bad(in);
        //cout << G << ' ' << B << endl;
        if (G != B) {
            printf("%d\n", in.front()); in.pop();
            for (int i = 0; i < n; ++i) {
                printf("%d ", in.front()); in.pop();
            }
            return 0;
        }
        while (!in.empty()) in.pop();
    }
    return 0;
}