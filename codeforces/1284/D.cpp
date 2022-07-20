#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

struct we {
    int x, y;
    unsigned long long i;
} a[N], b[N];
int n;

unsigned long long getHash() {
    unsigned long long ret = 0;
    for (int i = 0; i < 5; ++i) {
        ret ^= rand();
        ret <<= 13;
    }
    return ret;
}

vector<unsigned long long> calc(we t[N]) {
    vector<unsigned long long> ret;
    vector<pair<int, unsigned long long>> ends, starts;
    ends.emplace_back(-1, 0);
    starts.emplace_back(2e9, 0);
    for (int i = 0; i < n; ++i) {
        starts.emplace_back(t[i].x, t[i].i);
        ends.emplace_back(t[i].y, t[i].i);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 1; i <= n; ++i) {
        ends[i].second ^= ends[i-1].second;
    }
    for (int i = n-1; i >= 0; --i) {
        starts[i].second ^= starts[i+1].second;
    }
    const auto lambda = [](const pair<int, unsigned long long> &a, 
                           const pair<int, unsigned long long> &b) {
        return a.first < b.first;
    };
    for (int i = 0; i < n; ++i) {
        int L = lower_bound(ends.begin(), ends.end(), pair<int, unsigned long long>(t[i].x, 0), lambda)-ends.begin();
        int R = lower_bound(starts.begin(), starts.end(), pair<int, unsigned long long>(t[i].y+1, 0), lambda)-starts.begin();
        ret.push_back(ends[L-1].second ^ starts[R].second);
    }
    return ret;
}

int main() {
    srand(43);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y, u, v; scanf("%d%d%d%d", &x, &y, &u, &v);
        a[i].x = x; a[i].y = y;
        b[i].x = u; b[i].y = v;
        a[i].i = b[i].i = getHash();
    }
    printf(calc(a)==calc(b)?"YES":"NO");
    return 0;
}