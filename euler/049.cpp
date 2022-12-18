#include <bits/stdc++.h>

using namespace std;

bool checkprime(int n) {
    if (n % 2 == 0) return false;
    for (int i = 3, lim = sqrt(n); i <= lim; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

set<int> digits(int n) {
    set<int> s;
    while (n) {
        s.insert(n%10);
        n /= 10;
    }
    return s;
}

int main() {
    for (int i = 1000; i < 10000; ++i) {
        if (!checkprime(i)) continue;
        for (int j = 2; i+2*j < 10000; ++j) {
            if (!checkprime(i+j)) continue;
            if (!checkprime(i+j+j)) continue;
            auto d1 = digits(i);
            auto d2 = digits(i+j);
            if (d1 != d2) continue;
            auto d3 = digits(i+j+j);
            if (d1 != d3) continue;
            printf("%d%d%d\n", i, i+j, i+j+j);
            break;
        }
    }

    return 0;
}
