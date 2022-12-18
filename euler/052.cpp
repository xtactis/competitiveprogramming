#include <bits/stdc++.h>

using namespace std;

vector<int> digits(long long x) {
    vector<int> ret;
    while (x) {
        ret.push_back(x%10);
        x /= 10;
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    for (long long i = 1; ; ++i) {
        auto d = digits(i);
        bool allsame = true;
        for (int j = 2; j < 7; ++j) {
            auto e = digits(i*j);
            bool same = true;
            for (int k = 0; k < e.size(); ++k) {
                if (d[k] != e[k]) {
                    same = false;
                    break;
                }
            }
            if (!same) {
                allsame = false;
                break;
            }
        }
        if (allsame) {
            printf("%lld\n", i);
            break;
        }
    }

    return 0;
}
