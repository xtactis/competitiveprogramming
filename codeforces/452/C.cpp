#include <bits/stdc++.h>
using namespace std;

int main() {
    double n, m; cin >> n >> m;
    if (n == 1 && m == 1) return !printf("1");
    printf("%.16f", 1/n // the odds of getting the exact same card
     + (n-1)/n // the odds of not getting the exact same card
     * (m-1)/(n*m-1)); // the odds that a card has the same value as the
                       // one you selected but isn't the exact same card
    // the second part evaluates as "the odds that you chose a card
    // which isn't the exact same card, but has the same value as it"
    
    return 0;
}