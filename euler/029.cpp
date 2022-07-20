#include <bits/stdc++.h>
using namespace std;

int main() {
    set<vector<long long>> s;
    const int MAX = 1e9;
    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            vector<long long> v = {1};
            for (int i = 0; i < b; ++i) {
                int carry = 0;
                for (long long &e: v) {
                    e = e*a + carry;
                    carry = 0;
                    if (e >= MAX) {
                        carry = e / MAX;
                        e %= MAX;
                    }
                }
                if (carry) v.push_back(carry);
            }
            s.insert(v);
        }
    }
    printf("%d", s.size());
}