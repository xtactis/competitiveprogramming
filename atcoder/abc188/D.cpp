#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+23;

inline int sgn(long long x) {
    return x ? x > 0 ? 1 : -1 : 0;
}

int main() {
    long long n, C;
    scanf("%lld%lld", &n, &C);
    vector<pair<int, long long>> v;
    for (int a, b, c, i = 0; i < n; ++i) { 
        scanf("%d%d%d", &a, &b, &c);
        v.emplace_back(a, c);
        v.emplace_back(b+1, -c);
    }
    sort(v.begin(), v.end());
    vector<pair<int, long long>> w;
    for (const auto &e: v) {
        if (w.empty() || w.back().first != e.first || sgn(e.second) != sgn(w.back().second)) {
            w.emplace_back(e);
        } else {
            w.back().second += e.second;
        }
    }
    long long ans = 0;
    long long cur = 0;
    long long pd = -1;
    for (const auto &e: w) {
        long long fact = e.first-pd;
        if (pd != -1) {
            if (cur > C) {
                ans += fact*C;
            } else {
                ans += fact*cur;
            }
        }
        cur += e.second;
        pd = e.first;
    }
    printf("%lld\n", ans);
}