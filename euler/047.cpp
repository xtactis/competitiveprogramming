#include <bits/stdc++.h>

using namespace std;

set<int> factors(int n) {
    set<int> f;
    while (n%2 == 0) {
        f.insert(2);
        n /= 2;
    }
    for (int i = 3, lim = sqrt(n); i <= lim && n > 1; i += 2) {
        while (n % i == 0) {
            f.insert(i);
            n /= i;
        }
    }
    if (n > 1) {
        f.insert(n);
    }
    return f;
}

int main() {
    int cnt = 0;
    for (int i = 4; ; ++i) {
        auto f = factors(i);
//        for (int e: f) {
//            printf("%d ", f);
//        }
//        puts("");
        if (f.size() != 4) {
            cnt = 0;
        } else {
            cnt += 1;
        }
        if (cnt == 4) {
            printf("%d\n", i-3);
            break;
        }
    }
    return 0;
}
