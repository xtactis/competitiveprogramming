#include <bits/stdc++.h>

using namespace std;

int main() {
    int digs = 1;
    int total = 1;
    for (int i = 1; digs <= 1000000; ++i) {
        string s = to_string(i);
        for (char c: s) {
            if (digs == 10 || digs == 100 || digs == 1000 || digs == 10000 || digs == 100000 || digs == 1000000) {
                total *= c-'0';
            }
            ++digs;
        }
    }
    printf("%d\n", total);


    return 0;
}
