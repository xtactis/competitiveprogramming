#include <bits/stdc++.h>
using namespace std;

int len(int x) {
    if (!x) return 0;
    return len(x/10)+1;
}

int cat(int a, int b) {
    return b+(int)pow(10, len(b))*a;
}

bool alldigits(int x) {
    int arr[10] = {};
    while (x) {
        ++arr[x%10];
        x /= 10;
    }
    for (int i = 1; i < 10; ++i) {
        if (arr[i] != 1) return false;
    }
    return true;
}

int check(int i) {
    int x = i;
    for (int k = 2; len(x) < 9; ++k) {
        x = cat(x, k*i);
    }
    if (len(x) != 9) return 0;
    if (!alldigits(x)) return 0;
    return x;
}

int main() {
    int ans = 0;
    for (int i = 1; i < 10000; ++i) {
        ans = max(ans, check(i));
    }
    printf("%d\n", ans);
    return 0;
}