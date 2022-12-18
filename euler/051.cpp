#include <bits/stdc++.h>

using namespace std;

pair<int, int> arst(const set<int> &primes, int p) {
    vector<int> digits;
    int P = p;
    while (P) {
        digits.push_back(P%10);
        P /= 10;
    }
    reverse(digits.begin(), digits.end());
    int ret = 0;
    int smallest = 99999999;
    for (int mask = 0; mask < (1 << digits.size()); ++mask) {
        int startfrom = mask & 1;
        set<int> found;
        for (int j = startfrom; j < 10; ++j) {
            int newp = 0;
            for (int d = 0; d < digits.size(); ++d) {
                newp *= 10;
                if ((1<<d)&mask) {
                    newp += j;
                } else {
                    newp += digits[d];
                }
            }
            if (primes.count(newp)) {
                found.insert(newp);
            }
        }
        if (found.size() > ret) {
            smallest = *found.begin();
            ret = found.size();
        }
    }
    return {ret, smallest};
}

int main() {
    set<int> primes;
    primes.insert(2);
    for (int i = 3; i < 1000000; i += 2) {
        bool isprime = true;
        int lim = sqrt(i);
        for (int p: primes) {
            if (p > lim) break;
            if (i % p == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            primes.insert(i);
        }
    }
    for (int p: primes) {
        auto [c, pp] = arst(primes, p);
        if (c == 8) {
            printf("%d\n", pp);
            break;
        }
    }

    return 0;
}
